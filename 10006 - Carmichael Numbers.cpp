#include <iostream>

using namespace std;

int main()
{
	int number;
	int carmichaelNumbers[16] = {561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973};

	do
	{
		cin >> number;
		if (number == 0)
			return 0;

		bool flag = false;

		for (int i = 0; i < 16; i++)
		{
			if (carmichaelNumbers[i] == number)
			{
				flag = true;
				break;
			}
		}

		if (flag)
			cout << "The number " << number << " is a Carmichael number." << endl;
		else
			cout << number << " is normal." << endl;
	} while (number != 0);

	return 0;
}
