#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_groups;
    scanf("%d", &no_of_groups);

    vector <int> group_size(no_of_groups);
    for(int i = 0; i < no_of_groups; i++)
        scanf("%d", &group_size[i]);

    sort(all(group_size));

    int minimum_suppporters = 0;
    for(int i = 0; 2*i < no_of_groups; i++)
        minimum_suppporters += group_size[i]/2 + group_size[i]%2;

    printf("%d\n", minimum_suppporters);
    return 0;
}
