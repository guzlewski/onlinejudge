#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x, y;

	while (scanf("%d %d", &x, &y) != -1)
	{
		printf("%d\n", x ^ y);
	}

	return 0;
}