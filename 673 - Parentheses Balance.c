#include <stdio.h>
#include <stdlib.h>

struct stack
{
	char data;
	int count;
	struct stack* next;
};

void Push(struct stack** s, char d)
{
	struct stack* newelement = (struct stack*) malloc(sizeof(struct stack));
	newelement->data = d;
	newelement->next = *s;

	if (*s == NULL) newelement->count = 0;
	else newelement->count = (*s)->count + 1;

	*s = newelement;
}

void Delete(struct stack** s)
{
	while (*s != NULL)
	{
		struct stack* p = *s;
		*s = (*s)->next;
		free(p);
	}
}

char Pop(struct stack** s)
{
	if (*s == NULL) return '\0';

	struct stack* p = *s;
	char d = (*s)->data;
	*s = (*s)->next;
	free(p);
	return d;
}

int main()
{
	int tests, i;
	scanf("%d", &tests);
	getc(stdin);

	char tab[130];
	while (tests-- != 0)
	{
		for (i = 0; i < 130; i++) tab[i] = '\0';
		fgets(tab, 130, stdin);

		int ok = 1;
		struct stack* s = NULL;
		for (i = 0; i < 130; i++)
		{
			if (tab[i] == '(') Push(&s, ')');
			else if (tab[i] == '[') Push(&s, ']');
			else if (tab[i] == ')' || tab[i] == ']')
			{
				if (Pop(&s) != tab[i])
				{
					ok = 0;
					break;
				}
			}
		}

		if (ok != 0 && s == NULL) printf("Yes\n");
		else printf("No\n");
		Delete(&s);
	}

	return 0;
}