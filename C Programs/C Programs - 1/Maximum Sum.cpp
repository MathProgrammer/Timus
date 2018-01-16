#include <cstdio>

#define max(a, b) (a > b ? a : b)

int main()
{
    int n;
    scanf("%d", &n);

    int row_sum[n + 2][n + 2];

    for(int i = 1; i <= n; i++)
    {
        row_sum[i][0] = 0;

        for(int j = 1; j <= n; j++)
        {
            int rectangle_i_j;

            scanf("%d", &rectangle_i_j);

            row_sum[i][j] = row_sum[i][j - 1] + rectangle_i_j;
        }
    }

    const int oo = 1e9;
    int max_sum = -oo;
    for(int column_1 = 1; column_1 <= n; column_1++)
    {
        for(int column_2 = column_1; column_2 <= n; column_2++)
        {
            int max_sum_in_these_columns = -oo, max_sum_ending_here = -oo;

            for(int row = 1; row <= n; row++)
            {
                int current_row_sum = row_sum[row][column_2] - row_sum[row][column_1 - 1];

                max_sum_ending_here = current_row_sum + max(max_sum_ending_here, 0);

                max_sum_in_these_columns = max(max_sum_ending_here, max_sum_in_these_columns);
            }

            max_sum = max(max_sum, max_sum_in_these_columns);
        }
    }

    printf("%d\n", max_sum);
    return 0;
}
