#include <iostream>
#include <vector>

int main()
{
	while (true)
	{
		int n;
		std::cin >> n;

		if (n == 0)
		{
			break;
		}

		int streak = 0, sum;
		std::vector<int> bets;

		for (int i = 0; i < n; i++)
		{
			int bet;
			std::cin >> bet;
			bets.push_back(bet);
		}

		for (int i = 0; i < n; i++)
		{
			sum = 0;

			for (int j = i; j < n; j++)
			{
				sum += bets[j];

				if (sum > streak)
				{
					streak = sum;
				}
			}
		}

		if (streak <= 0)
		{
			std::cout << "Losing streak." << std::endl;
		}
		else
		{
			std::cout << "The maximum winning streak is " << streak << "." << std::endl;
		}
	}
}