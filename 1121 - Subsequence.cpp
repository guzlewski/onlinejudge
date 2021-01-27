#include <iostream>
#include <vector>

int main()
{
	int n, s;

	while (std::cin >> n >> s)
	{
		int min = 0, start = 0;
		int* tab = new int[n]();

		for (int i = 0; i < n; i++)
		{
			int t;
			std::cin >> t;

			for (int j = start; j <= i; j++)
			{
				tab[j] += t;

				if (tab[j] >= s)
				{
					start = j + 1;

					if (i - j + 1 < min || min == 0)
					{
						min = i - j + 1;
					}
				}
			}
		}

		std::cout << min << std::endl;
		delete[] tab;
	}
}