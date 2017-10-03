#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <int> &prime, int LIMIT)
{
    vector <int> is_prime(LIMIT, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i < LIMIT; i++)
    {
        if(is_prime[i])
            prime.push_back(i);

        for(int j = 0; j < prime.size() && i*prime[j] < LIMIT; j++)
        {
            is_prime[i*prime[j]] = false;

            if(i%prime[j] == 0) break;
        }
    }
}

int main()
{
    const int LIMIT = 2e5;
    vector <int> prime;
    precompute(prime, LIMIT);

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", prime[n - 1]);
    }

    return 0;
}
