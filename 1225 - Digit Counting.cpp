#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	while (n--)
	{
		int number;
		std::cin >> number;

		int tab[10] = {0};

		for (int i = 1; i <= number; i++)
		{
			int temp = i;
			while (temp != 0)
			{
				tab[temp % 10]++;
				temp /= 10;
			}
		}

		std::cout << tab[0];
		for (int i = 1; i < 10; i++)
		{
			std::cout << " " << tab[i];
		}
		std::cout << std::endl;
	}
}
