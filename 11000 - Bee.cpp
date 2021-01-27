#include <iostream>

int main()
{
	while (true)
	{
		int years;
		std::cin >> years;

		if (years == -1)
		{
			break;
		}

		unsigned int male = 0, female = 1, femaleOld = 0;

		for (int i = 0; i < years; i++)
		{
			unsigned int tempMale = female + male;
			unsigned int tempFemale = female + femaleOld;

			femaleOld = female;
			female = tempFemale;
			male = tempMale;
		}

		std::cout << male << " " << male + female << std::endl;
	}
}