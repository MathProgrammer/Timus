#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_VERTICES = 100 + 5, ROOT = 1;
typedef pair <int, int> pair_int;
typedef unsigned int u_int;

int max_apples_from[MAX_VERTICES][MAX_VERTICES];
vector <pair_int> tree[MAX_VERTICES];

int get_max_apples_from(int parent, int v, int preserved_branches)
{
    if(max_apples_from[v][preserved_branches] == -1)
    {
        max_apples_from[v][preserved_branches] = 0;

        if(preserved_branches == 0) return max_apples_from[v][preserved_branches];

        int child_1 = 0, apples_1 = 0, child_2 = 0, apples_2 = 0;
        for(u_int i = 0; i < tree[v].size(); i++)
        {
            if(parent == tree[v][i].first) continue;

            if(child_1 == 0)
            {
                child_1   = tree[v][i].first;
                apples_1  = tree[v][i].second;

                max_apples_from[v][preserved_branches] = max(apples_1 + get_max_apples_from(v, child_1, preserved_branches - 1),
                                                           max_apples_from[v][preserved_branches]);
            }
            else
            {
                child_2   = tree[v][i].first;
                apples_2  = tree[v][i].second;

                max_apples_from[v][preserved_branches] = max(apples_2 + get_max_apples_from(v, child_2, preserved_branches - 1),
                                                           max_apples_from[v][preserved_branches]);

            }
        }

        for(int i = 0; i <= preserved_branches - 2; i++)
        {
            max_apples_from[v][preserved_branches] = max(apples_1 + get_max_apples_from(v, child_1, preserved_branches - 2 - i) +
                                                       apples_2 + get_max_apples_from(v, child_2, i) ,
                                                       max_apples_from[v][preserved_branches]);

        }
    }

    return max_apples_from[v][preserved_branches];
}

int main()
{
    int no_of_vertices, preserved_branches;
    scanf("%d %d", &no_of_vertices, &preserved_branches);

    for(int i = 1; i < no_of_vertices; i++)
    {
        int x, y, apples;
        scanf("%d %d %d", &x, &y, &apples);

        tree[x].push_back(make_pair(y, apples));
        tree[y].push_back(make_pair(x, apples));
    }

    memset(max_apples_from, -1, sizeof(max_apples_from));

    int maximum_apples = get_max_apples_from(0, ROOT, preserved_branches);
    printf("%d\n", maximum_apples);

    return 0;
}
