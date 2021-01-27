#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

#define MAX INT_MAX >> 1

int main()
{
	int caseNr = 0;
	while (++caseNr)
	{
		int p, r;
		std::cin >> p >> r;

		if (p == 0 && r == 0)
		{
			break;
		}

		int* connections = new int[p * p];

		for (int i = 0; i < p; i++)
		{
			for (int j = 0; j < p; j++)
			{
				if (i == j)
				{
					connections[i * p + j] = 0;
				}
				else
				{
					connections[i * p + j] = MAX;
				}
			}
		}

		int index = 0;
		std::unordered_map<std::string, int> people;

		for (int i = 0; i < r; i++)
		{
			std::string from, to;
			std::cin >> from >> to;

			if (people.find(from) == people.end())
			{
				people[from] = index++;
			}

			if (people.find(to) == people.end())
			{
				people[to] = index++;
			}

			connections[people[from] * p + people[to]] = 1;
			connections[people[to] * p + people[from]] = 1;
		}

		for (int k = 0; k < p; k++)
		{
			for (int i = 0; i < p; i++)
			{
				for (int j = 0; j < p; j++)
				{
					connections[i * p + j] = std::min(connections[i * p + j], connections[i * p + k] + connections[k * p + j]);
				}
			}
		}

		int max = 0;
		bool connected = true;

		for (int i = 0; i < p && connected; i++)
		{
			for (int j = 0; j < p && connected; j++)
			{
				if (connections[i * p + j] == MAX)
				{
					connected = false;
				}

				max = std::max(max, connections[i * p + j]);
			}
		}

		std::cout << "Network " << caseNr << ": ";

		if (connected)
		{
			std::cout << max;
		}
		else
		{
			std::cout << "DISCONNECTED";
		}

		std::cout << std::endl << std::endl;

		delete[] connections;
	}
}