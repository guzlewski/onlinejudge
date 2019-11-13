#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int IsLetter(char x)
{
	return isalpha(x);
}

int main()
{
	int len, i, j, ignore = 0, index;
	char tab[62], word[62];

	while (1)
	{
		fgets(tab, 62, stdin);
		if (strlen(tab) == 2 && tab[0] == '#') break;

		if (!ignore)
		{
			for (i = 0; i < 62; i++)
				word[i] = -1;

			index = 0;
		}

		len = strlen(tab);

		for (i = 0; i < len; i++)
		{
			if (IsLetter(tab[i]))
			{
				word[index] = tab[i];
				index++;
			}
			else if (isspace(tab[i]))
			{
				for (j = 0; j < 62; j++)
				{
					if (word[j] != -1)
						printf("%c", word[j]);
				}

				if (ignore)
				{
					ignore = 0;
					printf("\n");
				}

				printf("%c", tab[i]);

				for (j = 0; j < 62; j++) word[j] = -1;
				index = 0;
			}
			else if (tab[i] == '-' && i + 1 < len && isspace(tab[i + 1]))
			{
				printf("\n");
				ignore = 1;
				i++;
			}
		}
	}

	return 0;
}