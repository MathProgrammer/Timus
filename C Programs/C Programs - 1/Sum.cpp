#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	int sum = (n > 0 ? n*(n + 1)/2 : 1 - ( (-n)*(-n + 1)/2 ) );

	printf("%d\n", sum);
	return 0;
}
