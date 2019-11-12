#include <iostream>

using namespace std;

int main()
{
	int tests;
	cin >> tests;

	while (tests--)
	{
		int n, m;
		cin >> n >> m;
		int tab[n][m];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				tab[i][j] = 0;

		int sonars = 0;
		for (int i = 1; i < n - 1; i += 3)
		{
			for (int j = 1; j < m - 1; j += 3)
			{
				if (tab[i][j] == 0)
				{
					sonars++;
					tab[i][j] = 1;
					tab[i][j + 1] = 1;
					tab[i][j - 1] = 1;

					tab[i - 1][j] = 1;
					tab[i - 1][j + 1] = 1;
					tab[i - 1][j - 1] = 1;

					tab[i + 1][j] = 1;
					tab[i + 1][j + 1] = 1;
					tab[i + 1][j - 1] = 1;
				}
			}
		}

		cout << sonars << endl;
	}

	return 0;
}