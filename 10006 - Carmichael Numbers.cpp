#include <iostream>

using namespace std;

int main()
{
	int carmichaels[16] = { 561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973 };

	int liczba;
	do
	{
		cin >> liczba;
		if (liczba == 0) return 0;

		bool ok = false;

		for (int i = 0; i < 16; i++)
		{
			if (carmichaels[i] == liczba)
			{
				ok = true;
				break;
			}
		}

		if (ok) cout << "The number " << liczba << " is a Carmichael number." << endl;
		else cout << liczba << " is normal." << endl;
	} while (liczba != 0);

	return 0;
}
