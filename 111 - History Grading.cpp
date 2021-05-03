#include <iostream>

using namespace std;

int c[21];
int good[21];
int tab[21][21];

int lcs(int i, int j)
{
	if (i == 0 || j == 0)
		return 0;
	if (tab[i][j] != -1)
		return tab[i][j];
	if (good[i] == c[j])
	{
		tab[i][j] = 1 + lcs(i - 1, j - 1);
		return tab[i][j];
	}

	tab[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
	return tab[i][j];
}

int main()
{
	int n, temp;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		good[temp] = i;
	}

	while (cin >> temp)
	{
		c[temp] = 1;
		for (int i = 2; i <= n; i++)
		{
			cin >> temp;
			c[temp] = i;
		}

		for (int i = 0; i < 21; i++)
			for (int j = 0; j < 21; j++)
				tab[i][j] = -1;

		cout << lcs(n, n) << endl;
	}

	return 0;
}