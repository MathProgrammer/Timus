#include <cstdio>

int main()
{
    char code_1[4], code_2[4];
    scanf("%s %s", code_1, code_2);

    int last_digit_code_1 = code_1[3] - '0', last_digit_code_2 = code_2[3] - '0';

    int code_1_even = (last_digit_code_1%2 == 0 ? true : false);
    int code_2_odd  = (last_digit_code_2%2 == 1 ? true : false);

    printf(code_1_even || code_2_odd ? "yes\n" : "no\n");
    return 0;
}
