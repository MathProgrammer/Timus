#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_horses, no_of_stables;
    scanf("%d %d", &no_of_horses, &no_of_stables);

    vector <int> colour(no_of_horses + 1);
    vector <int> black_horses_till(no_of_horses + 1, 0);
    for(int i = 1; i <= no_of_horses; i++)
    {
        scanf("%d", &colour[i]);
        black_horses_till[i] = (colour[i] == 1) + black_horses_till[i - 1];
    }

    typedef vector <int> v_int;
    vector <v_int> minimum_unhappiness_till(no_of_horses + 1, v_int(no_of_stables + 1, 1e9));

    minimum_unhappiness_till[0][0] = 0;

    for(int i = 1; i <= no_of_horses; i++)
    {
        for(int k = 1; k <= min(i, no_of_stables); k++)
        {
            for(int j = 0; j < i; j++)
            {
                int horses_in_stable = i - j;
                int black_horses = black_horses_till[i] - black_horses_till[j], white_horses = horses_in_stable - black_horses;
                int unhappiness = white_horses*black_horses;

                minimum_unhappiness_till[i][k] = min(minimum_unhappiness_till[i][k], unhappiness + minimum_unhappiness_till[j][k - 1]);
            }
        }
    }

    printf("%d\n", minimum_unhappiness_till[no_of_horses][no_of_stables]);
    return 0;
}
