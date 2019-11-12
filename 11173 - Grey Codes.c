#include <stdio.h>
#include <stdlib.h>

int main()
{
	int cases, n, k;
	scanf("%d", &cases);

	while (cases--)
	{
		scanf("%d %d", &n, &k);
		printf("%d\n", k ^ (k / 2));
	}

	return 0;
}