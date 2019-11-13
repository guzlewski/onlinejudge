#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x, y, j, i;

	while (1)
	{
		scanf("%d", &x);

		if (x == 0)
			break;

		y = x;
		j = 0;

		while (x != 0)
		{
			if (x & 1) j++;
			x >>= 1;
		}

		printf("The parity of ");

		int tab[40];

		for (i = 0; i < 40; i++)
			tab[i] = -1;

		for (i = 0; i < 40; i++)
		{
			if (y == 0)
				break;

			tab[i] = y & 1;
			y = y >> 1;
		}
		for (i = 40 - 1; i >= 0; i--)
		{
			if (tab[i] == -1)
				continue;

			printf("%d", tab[i]);
		}

		printf(" is %d (mod 2).\n", j);
	}

	return 0;
}