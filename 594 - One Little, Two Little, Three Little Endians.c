#include <stdio.h>
#include <stdlib.h>

union number
{
	int i;
	char tab[4];
};

int main()
{
	char t;
	int x, rev;

	while (scanf("%d", &x) != EOF)
	{
		printf("%d converts to ", x);

		union number n;
		n.i = x;

		t = n.tab[0];
		n.tab[0] = n.tab[3];
		n.tab[3] = t;

		t = n.tab[1];
		n.tab[1] = n.tab[2];
		n.tab[2] = t;

		printf("%d\n", n.i);
	}

	return 0;
}