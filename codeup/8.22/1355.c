#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = n; i >= 1; i--)
	{
		for (int k = 1; k <= n - i; k++)
		{
			printf(" ");
		}
		for (int j = 1; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
