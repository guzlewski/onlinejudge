#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int power(int x, int y)
{
	if (y == 0)
		return 1;
	else
		return (int)pow(x, y);
}

int main()
{
	int rounds, i, j;

	while (1)
	{
		if (scanf("%d %d %d", &rounds, &i, &j) == EOF)
			break;

		int result = 0;

		while (i != j)
		{
			if (i % 2 != 0)
				i++;

			if (j % 2 != 0)
				j++;

			i /= 2;
			j /= 2;

			result++;
		}
		printf("%d\n", result);
	}

	return 0;
}