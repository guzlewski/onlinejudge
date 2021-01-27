#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 2000000000
#define PRECISION 31

void generate(std::vector<int>& humble)
{
	for (int i = 0; i < PRECISION; i++)
	{
		for (int j = 0; j < PRECISION; j++)
		{
			for (int k = 0; k < PRECISION; k++)
			{
				for (int m = 0; m < PRECISION; m++)
				{
					int number = (int)(std::pow(2, i) * std::pow(3, j) * std::pow(5, k) * std::pow(7, m));

					if (number > MAX || number < 0)
					{
						break;
					}

					humble.push_back(number);
				}
			}
		}
	}

	std::sort(humble.begin(), humble.end());
}

int main()
{
	std::vector<int> humble;
	generate(humble);

	int n;
	while (std::cin >> n && n != 0)
	{
		int reminder = n % 10;
		bool exception = n % 100 >= 10 && n % 100 < 20;

		std::cout << "The " << n;

		if (reminder == 1 && !exception)
		{
			std::cout << "st";
		}
		else if (reminder == 2 && !exception)
		{
			std::cout << "nd";
		}
		else if (reminder == 3 && !exception)
		{
			std::cout << "rd";
		}
		else
		{
			std::cout << "th";
		}

		std::cout << " humble number is " << humble[n - 1] << "." << std::endl;
	}
}