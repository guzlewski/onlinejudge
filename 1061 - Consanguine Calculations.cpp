#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> calculateChild(std::string p1, std::string p2)
{
	std::vector<std::string> results;

	if ((p1[0] == 'A' && p1[1] == 'B') || (p2[0] == 'A' && p2[1] == 'B'))
	{
		if (p1[0] == 'O' || p2[0] == 'O')
		{
			results.push_back("A");
			results.push_back("B");
		}
		else
		{
			results.push_back("A");
			results.push_back("AB");
			results.push_back("B");
		}
	}
	else if ((p1[0] == 'A' && p2[0] == 'B') || (p1[0] == 'B' && p2[0] == 'A'))
	{
		results.push_back("A");
		results.push_back("AB");
		results.push_back("B");
		results.push_back("O");
	}
	else if (p1[0] == 'A' || p2[0] == 'A')
	{
		results.push_back("A");
		results.push_back("O");
	}
	else if (p1[0] == 'B' || p2[0] == 'B')
	{
		results.push_back("B");
		results.push_back("O");
	}
	else if (p1[0] == 'O' && p2[0] == 'O')
	{
		results.push_back("O");
	}

	if (p1[p1.length() - 1] == '-' && p2[p2.length() - 1] == '-')
	{
		for (auto& x : results)
		{
			x += '-';
		}
	}
	else
	{
		std::vector<std::string> temp;

		for (auto& x : results)
		{
			temp.push_back(x + "+");
			temp.push_back(x + "-");
		}

		results = temp;
	}

	return results;
}

std::vector<std::string> calculateParent(std::string p1, std::string child)
{
	std::vector<std::string> results;
	std::string tab[] = { "A+", "A-", "AB+", "AB-", "B+", "B-", "O+", "O-" };

	for (auto& x : tab)
	{
		auto temp = calculateChild(p1, x);

		if (std::find(temp.begin(), temp.end(), child) != temp.end())
		{
			results.push_back(x);
		}
	}

	return results;
}

int main()
{
	int caseNr = 0;

	while (true)
	{
		std::string p1, p2, child;
		std::cin >> p1 >> p2 >> child;

		if (p1 == "E" && p2 == "N" && child == "D")
		{
			break;
		}

		if (p1 != "?" && p2 != "?")
		{
			auto results = calculateChild(p1, p2);

			std::cout << "Case " << ++caseNr << ": " << p1 << " " << p2 << " ";

			if (results.size() == 1)
			{
				std::cout << results[0];
			}
			else
			{
				std::cout << "{";

				for (unsigned int i = 0; i < results.size(); i++)
				{
					std::cout << results[i];

					if (i + 1 < results.size())
					{
						std::cout << ", ";
					}
				}

				std::cout << "}";
			}

			std::cout << std::endl;
		}
		else
		{
			if (p1 == "?")
			{
				std::swap(p1, p2);
			}

			auto results = calculateParent(p1, child);

			std::cout << "Case " << ++caseNr << ": " << p1 << " ";

			if (results.size() == 0)
			{
				std::cout << "IMPOSSIBLE";
			}
			else if (results.size() == 1)
			{
				std::cout << results[0];
			}
			else
			{
				std::cout << "{";

				for (unsigned int i = 0; i < results.size(); i++)
				{
					std::cout << results[i];

					if (i + 1 < results.size())
					{
						std::cout << ", ";
					}
				}

				std::cout << "}";
			}

			std::cout << " " << child << std::endl;
		}
	}
}
