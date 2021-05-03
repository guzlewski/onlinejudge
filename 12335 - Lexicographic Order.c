#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len, vis[20], ind[20];

long long powers[20];

void Process(int cur, long long dir)
{
	if (cur == len)
		return;

	int i;
	long long temp = powers[len - cur - 1];

	for (i = 0; i < len; i++)
	{
		if (vis[i])
			continue;
		if (dir > temp)
			dir -= temp;
		else
		{
			vis[i] = 1;
			ind[cur] = i;
			Process(cur + 1, dir);
			break;
		}
	}
}

int main()
{
	int i, tests, caseN = 0;

	powers[0] = 1;
	for (i = 1; i < 20; i++)
		powers[i] = powers[i - 1] * i;

	long long x;
	scanf("%d", &tests);

	while (tests--)
	{
		char str[20], ans[20];

		scanf("%s %lld", str, &x);

		len = strlen(str);
		memset(vis, 0, sizeof(vis));

		Process(0, x);

		printf("Case %d: ", ++caseN);

		for (i = 0; i < len; i++)
			ans[ind[i]] = str[i];

		for (i = 0; i < len; i++)
			printf("%c", ans[i]);

		printf("\n");
	}

	return 0;
}