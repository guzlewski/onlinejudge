#include <iostream>
#include <cmath>
#include <vector>

int main()
{
	int n, m;
	while (std::cin >> n >> m)
	{
		if (m == 0 || m == 1 || m > n)
		{
			std::cout << "Boring!" << std::endl;
			continue;
		}

		std::vector<int> powers;

		for (long i = 1; i <= n; i *= m)
		{
			powers.push_back(i);
		}

		if (powers[powers.size() - 1] != n)
		{
			std::cout << "Boring!" << std::endl;
			continue;
		}

		std::cout << powers[powers.size() - 1];

		for (int i = powers.size() - 2; i >= 0; i--)
		{
			std::cout << " " << powers[i];
		}

		std::cout << std::endl;
	}
}