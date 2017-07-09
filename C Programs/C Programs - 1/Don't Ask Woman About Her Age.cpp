#include <cstdio>

#define MAX_LENGTH 1000000 + 2
#define max(a, b) (a > b ? a : b);

int main()
{
    char number[MAX_LENGTH];
    scanf("%s", number);

    int minimum_base = 2;
    int digit_sum = 0;
    for(int i = 0; number[i] != '\0'; i++)
    {
        int current_number = (number[i] >= 'A' && number[i] <= 'Z' ? 10 + number[i] - 'A' : number[i] - '0');

        digit_sum += current_number;
        minimum_base = max(minimum_base, current_number + 1);
    }

    const int MAX_BASE = 36;
    int answer = -1;
    for(int i = minimum_base - 1; i < MAX_BASE; i++)
    {
        if(digit_sum%i == 0)
        {
            answer = i + 1;
            break;
        }
    }

    printf(answer == -1 ?  "No solution.\n" : "%d\n", answer);
    return 0;
}
