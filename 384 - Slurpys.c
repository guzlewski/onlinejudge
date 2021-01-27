#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int FindSlump(char* tab, int index)
{
	int dl = strlen(tab), i = index;

	if (tab[i] == 'D' || tab[i] == 'E')
	{
		i++;

		while (i < dl && tab[i] == 'F')
			i++;

		if (i >= dl)
			return -1;

		if (tab[i] == 'G')
			return i;
		else
			return FindSlump(tab, i);
	}
	return -1;
}

int FindSlimp(char* tab, int index)
{
	int dl = strlen(tab), i = index, end;

	if (tab[i] == 'A')
	{
		if (i + 1 < dl && tab[i + 1] == 'H')
		{
			end = i + 1;

			return end;
		}
		else if (i + 1 < dl && tab[i + 1] == 'B')
		{
			int end = FindSlimp(tab, i + 2);

			if (end >= 0 && end + 1 < dl && tab[end + 1] == 'C')
				return end + 1;
			else
				return -1;
		}
		else if (i + 1 < dl)
		{
			int end = FindSlump(tab, i + 1);

			if (end >= 0 && end + 1 < dl && tab[end + 1] == 'C')
				return end + 1;
			else
				return -1;
		}
	}

	return -1;
}

int IsSlurpy(char* tab)
{
	int x = FindSlimp(tab, 0);

	if (x <= 0)
		return 0;

	x = FindSlump(tab, x + 1);

	if (x <= 0)
		return 0;

	return (x + 1) == (int)strlen(tab);
}

int main()
{
	int tests;
	scanf("%d", &tests);

	printf("SLURPYS OUTPUT\n");

	int slurpy;
	char tab[61];
	while (tests--)
	{
		memset(tab, 0, 61);

		scanf("%s", tab);
		slurpy = IsSlurpy(tab);

		if (slurpy > 0)
			printf("YES\n");
		else
			printf("NO\n");
	}

	printf("END OF OUTPUT\n");

	return 0;
}