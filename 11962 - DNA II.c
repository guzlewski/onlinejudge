#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum DNA
{
	A = 0,
	C = 1,
	G = 2,
	T = 3
};

unsigned long long power(int p, int x)
{
	if (x == 0)
		return 1;
	else
		return (unsigned long long)pow(p, x);
}

int main()
{
	int tests, caseN = 0, i, p;
	unsigned long long number;

	scanf("%d", &tests);

	char tab[60];
	while (tests-- != 0)
	{
		scanf("%s", tab);
		number = 0;
		p = 0;

		for (i = (int)strlen(tab) - 1; i >= 0; i--)
		{
			if (tab[i] == 'C')
				number = number + power(4, p);
			else if (tab[i] == 'G')
				number = number + 2 * power(4, p);
			else if (tab[i] == 'T')
				number = number + 3 * power(4, p);

			p++;
		}

		printf("Case %d: (%d:%llu)\n", ++caseN, (int)strlen(tab), number);
	}

	return 0;
}