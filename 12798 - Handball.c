#include <stdio.h>
#include <stdlib.h>

int main()
{
	int players, matches, i, j;

	while (scanf("%d %d", &players, &matches) != EOF)
	{
		int* tab = (int*)malloc(players * sizeof(int));

		for (j = 0; j < players; j++)
			tab[j] = 0;

		for (i = 0; i < players; i++)
		{
			int goal;

			for (j = 0; j < matches; j++)
			{
				scanf("%d", &goal);

				if (goal)
					tab[i]++;
			}
		}

		int c = 0;
		for (j = 0; j < players; j++)
		{
			if (tab[j] == matches)
				c++;
		}

		printf("%d\n", c);

		free(tab);
	}
	return 0;
}