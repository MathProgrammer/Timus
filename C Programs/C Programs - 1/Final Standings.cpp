#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct team_data
{
    int position;
	int id;
	int problems_solved;
};

bool compare_teams(const team_data &P, const team_data &Q) //true if P comes before Q
{
	if(P.problems_solved > Q.problems_solved)
		return true;
	else if(P.problems_solved < Q.problems_solved)
		return false;

    if(P.position < Q.position)
        return true;
    else
        return false;
}

int main()
{
	int no_of_teams;
	scanf("%d", &no_of_teams);

	vector <team_data> team(no_of_teams);
	for(int i = 0; i < no_of_teams; i++)
    {
        scanf("%d %d", &team[i].id, &team[i].problems_solved);
        team[i].position = i;
    }

	sort(all(team), &compare_teams);

	for(int i = 0; i < no_of_teams; i++)
		printf("%d %d\n",team[i].id, team[i].problems_solved);

	return 0;
}
