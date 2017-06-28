#include <cstdio>
#include <algorithm>

#define min_3(a, b, c) min(a, min(b, c) )
#define max_3(a, b, c) max(a, max(b, c) )

using namespace std;

int main()
{
    int a, b, c, answer;
    scanf("%d %d %d", &a, &b, &c);

    int x = min_3(a, b, c);
    int y = max_3(a, b, c);
    int z = (a + b + c) - (x + y);

    answer = min(x - (y*z), x - (y + z));

    printf("%d\n", answer);

    return 0;
}
