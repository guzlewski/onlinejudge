#include <iostream>
#include <cmath>

int main()
{
	int n;
	std::cin >> n;

	while (n--)
	{
		int p;
		char t;

		std::cin >> p >> t;

		if (p == 2 || p == 3 || p == 5 || p == 7 || p == 13 || p == 17)
		{
			std::cout << "Yes" << std::endl;
		}
		else
		{
			std::cout << "No" << std::endl;
		}
	}
}