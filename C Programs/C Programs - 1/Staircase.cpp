#include <cstdio>
#include <vector>

using namespace std;

typedef vector <long long> vll;

int main()
{
    int no_of_bricks;
    scanf("%d", &no_of_bricks);

    //f(i, j) represents the number of staircases with i bricks with the height of the largest stair at most j.
    vector <vector <long long> > no_of_ways(no_of_bricks + 1, vector <long long> (no_of_bricks + 1, 0) );


    no_of_ways[0][0] = 1;

    for(int last_height = 1; last_height <= no_of_bricks; last_height++)
    	no_of_ways[0][last_height] = no_of_ways[1][last_height] = 1;

    for(int bricks = 2; bricks <= no_of_bricks; bricks++)
    {
        for(int last_height = 1; last_height <= no_of_bricks - 1; last_height++)
        {
            no_of_ways[bricks][last_height] = no_of_ways[bricks][last_height - 1];

            if(bricks >= last_height)
            {
                no_of_ways[bricks][last_height] += no_of_ways[bricks - last_height][last_height - 1];
            }
        }
    }

    printf("%I64d\n", no_of_ways[no_of_bricks][no_of_bricks - 1]);
    return 0;
}

