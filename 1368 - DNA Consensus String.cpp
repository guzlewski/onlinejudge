#include <iostream>
#include <vector>
#include <map>
#include <utility>

std::pair<char, int> findnearest(std::vector<std::string> &input, int index)
{
	char c;
	int max = 0;
	std::map<char, int> codes;

	for (size_t i = 0; i < input.size(); i++)
	{
		codes[input[i][index]]++;
	}

	for (const auto &it : codes)
	{
		if (it.second > max)
		{
			c = it.first;
			max = it.second;
		}
	}

	return std::make_pair(c, input.size() - max);
}

int main()
{
	int tests;
	std::cin >> tests;

	while (tests--)
	{
		int n, s;
		std::cin >> n >> s;
		std::vector<std::string> tab;

		for (int j = 0; j < n; j++)
		{
			std::string str;
			std::cin >> str;
			tab.push_back(str);
		}

		std::string dna = "";
		int error = 0;

		for (int i = 0; i < s; i++)
		{
			std::pair<char, int> n = findnearest(tab, i);

			dna += n.first;
			error += n.second;
		}

		std::cout << dna << std::endl
				  << error << std::endl;
	}
}
