#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Char2Int(char x)
{
	switch (x)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;
	}

	return -1;
}

int String2Int(char *tab)
{
	int len = strlen(tab), i, j, sum = 0;

	for (i = len - 1, j = 0; i >= 0; i--, j++)
		sum += pow(16, j) * Char2Int(tab[i]);

	return sum;
}

void Print(int x, int dl)
{
	if (dl == 13)
		return;

	Print(x >> 1, dl + 1);
	printf("%d", x & 1);
}

int main()
{
	int tests;
	scanf("%d", &tests);

	while (tests--)
	{
		char l1[4], l2[4], sign;
		scanf("%s %c %s", l1, &sign, l2);

		int first = String2Int(l1), second = String2Int(l2), sum;

		if (sign == '+')
			sum = first + second;
		else
			sum = first - second;

		Print(first, 0);
		printf(" %c ", sign);

		Print(second, 0);
		printf(" = %d\n", sum);
	}

	return 0;
}