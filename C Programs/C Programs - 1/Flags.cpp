#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    const int RED = 0, WHITE = 1;

    int no_of_strips;
    scanf("%d", &no_of_strips);

    vector <vector <long long> > no_of_flags(2, vector <long long> (no_of_strips + 1, 0));

    //no_of_flags(RED, i) means no of combinations starting with RED flag of length i

    no_of_flags[RED][1] = no_of_flags[WHITE][1] = 1;
    for(int i = 2; i <= no_of_strips; i++)
    {
        no_of_flags[RED][i] = no_of_flags[WHITE][i - 1] + no_of_flags[WHITE][i - 2]; //RW and RBW
        no_of_flags[WHITE][i] = no_of_flags[RED][i - 1] + no_of_flags[RED][i - 2]; //WR and WBR
    }

    printf("%lld\n", no_of_flags[RED][no_of_strips] + no_of_flags[WHITE][no_of_strips]);


    return 0;
}
