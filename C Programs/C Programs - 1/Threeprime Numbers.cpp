#include <cstdio>
#include <vector>
#include <cstring>

const int MAX_DIGITS = 1e4 + 1, MAX_DIGIT_VALUE = 10, MOD = 1e9  + 9;
long long no_of_3_primes[MAX_DIGITS][MAX_DIGIT_VALUE][MAX_DIGIT_VALUE] = {{{0}}};

using namespace std;

int first_digit(int n)
{
    return (n/100);
}

int second_digit(int n)
{
    return (n/10)%10;
}

int third_digit(int n)
{
    return n%10;
}

void precompute(vector <int> &three_digit_primes)
{
    const int LIMIT = 1e3;
    vector <int> is_prime(LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= LIMIT; i++)
    {
        if(is_prime[i])
        {
            for(int multiple = i*i; multiple <= LIMIT; multiple += i)
                is_prime[multiple] = false;

            if(i > 100)
                three_digit_primes.push_back(i);
        }
    }
}

int main()
{
    vector <int> three_digit_primes;
    precompute(three_digit_primes);

    int no_of_digits;
    scanf("%d", &no_of_digits);

    for(int total_digits = 3; total_digits <= no_of_digits; total_digits++)
    {
        for(unsigned int i = 0; i < three_digit_primes.size(); i++)
        {
            int prime = three_digit_primes[i];

            if(total_digits == 3)
            {
                no_of_3_primes[total_digits][first_digit(prime)][second_digit(prime)]++;
            }
            else
            {
                no_of_3_primes[total_digits][first_digit(prime)][second_digit(prime)] +=

                                                            no_of_3_primes[total_digits - 1][second_digit(prime)][third_digit(prime)];

                no_of_3_primes[total_digits][first_digit(prime)][second_digit(prime)] %= MOD ;
            }
        }
    }


    long long no_of_3_primes_n_digits = 0;
    for(int digit_1 = 1; digit_1 < MAX_DIGIT_VALUE; digit_1++)
    {
        for(int digit_2 = 0; digit_2 < MAX_DIGIT_VALUE; digit_2++)
        {
            no_of_3_primes_n_digits += no_of_3_primes[no_of_digits][digit_1][digit_2];
            no_of_3_primes_n_digits %= MOD;
        }
    }

    printf("%I64d\n", no_of_3_primes_n_digits);
    return 0;
}

