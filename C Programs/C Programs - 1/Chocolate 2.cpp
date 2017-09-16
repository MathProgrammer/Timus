#include <cstdio>

int main()
{
    int row, column;
    scanf("%d %d", &row, &column);

    int no_of_pieces_at_end = row*column;
    printf(no_of_pieces_at_end%2 == 0 ? "[:=[first]" : "[second]=:]");

    return 0;
}
