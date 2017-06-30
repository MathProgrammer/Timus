#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_strips;
    scanf("%d", &no_of_strips);

    vector <long long> no_of_flags(no_of_strips + 1, 0);

    no_of_flags[1] = 2;
    for(int i = 2; i <= no_of_strips; i++)
    {
        no_of_flags[i] = no_of_flags[i - 1] + no_of_flags[i - 2];
    }

    printf("%lld\n",no_of_flags[no_of_strips]);
    return 0;
}
