#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int length, base;
    scanf("%d %d", &length, &base);

    vector <long long> no_of_valid_numbers_of_length(length + 5);
    no_of_valid_numbers_of_length[1] = base; //First digit can be any digit
    no_of_valid_numbers_of_length[2] = (base - 1)*base; //No leading 0s.
    no_of_valid_numbers_of_length[3] = (base - 1)*( no_of_valid_numbers_of_length[2] + (base - 1) );//Second digit can be non-0. If it is 0, last digit has n-1 choices.

    for(int i = 4; i <= length; i++)
    {
        //First digit can be chosen in base - 1 ways. After that, the second digit may be non-zero, counted by f(i-1),
        //Or second digit may be 0, in which case third digit can't be 0, counted by f(i-2).

        no_of_valid_numbers_of_length[i] = (base - 1)*( no_of_valid_numbers_of_length[i - 1] + no_of_valid_numbers_of_length[i - 2]);
    }

    printf("%I64d\n", no_of_valid_numbers_of_length[length]);
    return 0;
}
