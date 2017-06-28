#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	const int INFINITY = 1e9 + 1;
	int number_of_piles, min_difference = INFINITY;
	scanf("%d", &number_of_piles);

	vector <int> weight(number_of_piles);
	for(int i = 0; i < number_of_piles; i++)
		scanf("%d", &weight[i]);

	//N can be at most 20 ... This allows brute force checking
	int no_of_bitmasks = (1 << number_of_piles) - 1;
	for(int bitmask = 1; bitmask <= no_of_bitmasks; bitmask++)
	{
		int sum_1 = 0, sum_2 = 0;
		for(int i = 0; i < number_of_piles; i++)
		{
			if( (bitmask & (1 << i)) == 0)
				sum_1 += weight[i];
			else
				sum_2 += weight[i];
		}

		min_difference = min(min_difference, abs(sum_1 - sum_2));
	}

	printf("%d\n", min_difference);
	return 0;
}
