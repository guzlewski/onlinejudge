#include <iostream>

int main()
{
	int tests;
	std::cin >> tests;

	while (tests--)
	{
		int p, d;
		std::cin >> p >> d;

		int *tab = new int[p * p];

		for (int i = 0; i < p; i++)
		{
			for (int j = 0; j < p; j++)
			{
				if (i == j)
				{
					tab[i * p + j] = 0;
				}
				else
				{
					tab[i * p + j] = 10000;
				}
			}
		}

		for (int i = 0; i < d; i++)
		{
			int p1, p2;
			std::cin >> p1 >> p2;

			tab[p1 * p + p2] = 1;
			tab[p2 * p + p1] = 1;
		}

		for (int k = 0; k < p; k++)
		{
			for (int i = 0; i < p; i++)
			{
				for (int j = 0; j < p; j++)
				{
					tab[i * p + j] = std::min(tab[i * p + j], tab[i * p + k] + tab[k * p + j]);
				}
			}
		}

		for (int i = 1; i < p; i++)
		{
			std::cout << tab[i] << std::endl;
		}

		if (tests != 0)
		{
			std::cout << std::endl;
		}

		delete[] tab;
	}
}
