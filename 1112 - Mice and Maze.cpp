#include <iostream>

int main()
{
	int tests;
	std::cin >> tests;

	while (tests--)
	{
		int n, e, t, m;
		std::cin >> n >> e >> t >> m;
		e--;

		int *tab = new int[n * n];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					tab[i * n + j] = 0;
				}
				else
				{
					tab[i * n + j] = 1000;
				}
			}
		}

		for (int i = 0; i < m; i++)
		{
			int from, to, time;
			std::cin >> from >> to >> time;

			from--;
			to--;

			tab[from * n + to] = time;
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

		int count = 0;

		for (int i = 0; i < n; i++)
		{
			if (tab[i * n + e] <= t)
			{
				count++;
			}
		}

		std::cout << count << std::endl;

		if (tests != 0)
		{
			std::cout << std::endl;
		}

		delete[] tab;
	}
}
