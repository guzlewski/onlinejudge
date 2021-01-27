#include <iostream>
#include <string>
#include <cmath>

int findset(int* parent, int* value, int x)
{
	if (x == parent[x])
	{
		return x;
	}

	int root = findset(parent, value, parent[x]);
	value[x] += value[parent[x]];
	parent[x] = root;

	return parent[x];
}

int main()
{
	int tests;
	std::cin >> tests;

	while (tests--)
	{
		int n;
		std::cin >> n;

		int* parent = new int[n + 1];
		int* value = new int[n + 1];

		for (int i = 1; i < n + 1; i++)
		{
			parent[i] = i;
			value[i] = 0;
		}

		while (true)
		{
			char mode;
			std::cin >> mode;

			if (mode == 'O')
			{
				break;
			}
			else if (mode == 'E')
			{
				int i;
				std::cin >> i;

				findset(parent, value, i);
				std::cout << value[i] << std::endl;
			}
			else if (mode == 'I')
			{
				int i, j;
				std::cin >> i >> j;

				parent[i] = j;
				value[i] = std::abs(i - j) % 1000;
			}
		}

		delete[] parent;
		delete[] value;
	}
}