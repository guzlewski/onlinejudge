#include <iostream>

#define MAX 9999

int main()
{
	int tests, caseNr = 0;
	std::cin >> tests;

	while (tests--)
	{
		int n, r;
		std::cin >> n >> r;

		int* tab = new int[n * n];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					tab[i * n + j] = MAX;
				}
				else
				{
					tab[i * n + j] = 0;
				}
			}
		}

		for (int i = 0; i < r; i++)
		{
			int u, v;
			std::cin >> u >> v;

			tab[u * n + v] = 1;
			tab[v * n + u] = 1;
		}

		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					tab[i * n + j] = std::min(tab[i * n + j], tab[i * n + k] + tab[k * n + j]);
				}
			}
		}

		int start, end;
		std::cin >> start >> end;

		int time = 0;
		for (int i = 0; i < n; i++)
		{
			time = std::max(time, tab[start * n + i] + tab[i * n + end]);
		}

		std::cout << "Case " << ++caseNr << ": " << time << std::endl;
		delete[] tab;
	}
}
