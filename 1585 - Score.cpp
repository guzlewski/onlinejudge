#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;

		int sum = 0, counter = 1;

		for (size_t j = 0; j < str.length(); j++)
		{
			if (str[j] == 'X')
			{
				counter = 1;
			}
			else
			{
				sum += counter;
				counter++;
			}
		}

		std::cout << sum << std::endl;
	}
}