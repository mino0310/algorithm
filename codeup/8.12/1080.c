#include <stdio.h>
int main(void)
{
	int n, i, sum = 0;
	scanf("%d", &n);

	for (i = 1; sum < n; i++)
	{
		sum += i;
	}
	printf("%d", i - 1);
	return 0;
}
