#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x, casenr = 0;

	while (1)
	{
		scanf("%d", &x);
		if (x < 0) break;

		if (x == 1)
		{
			printf("Case %d: %d\n", ++casenr, 0);
		}
		else
		{
			int sum = 1, p = 0;
			while (sum < x)
			{
				sum <<= 1;
				p++;
			}

			printf("Case %d: %d\n", ++casenr, p);
		}
	}

	return 0;
}