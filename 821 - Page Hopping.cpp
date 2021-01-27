#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

int main()
{
	int from, to, caseNr = 0;

	while (std::cin >> from >> to && from != 0 && to != 0)
	{
		int index = 0;
		std::unordered_map<int, int> rules;
		std::unordered_map<int, std::unordered_set<int>> edges;

		do
		{
			if (rules.find(from) == rules.end())
			{
				rules[from] = index++;
			}

			if (rules.find(to) == rules.end())
			{
				rules[to] = index++;
			}

			edges[rules[from]].insert(rules[to]);

		} while (std::cin >> from >> to && from != 0 && to != 0);

		int n = rules.size();
		int* tab = new int[n * n];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					tab[i * n + j] = 0;
				}
				else if (edges[i].find(j) != edges[i].end())
				{
					tab[i * n + j] = 1;
				}
				else
				{
					tab[i * n + j] = 1000;
				}
			}
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

		int sum = 0;

		for (int i = 0; i < n * n; i++)
		{
			sum += tab[i];
		}

		std::cout << "Case " << ++caseNr << ": average length between pages = " << std::fixed << std::setprecision(3) << sum / (n * ((double)n - 1)) << " clicks" << std::endl;

		delete[] tab;
	}
}