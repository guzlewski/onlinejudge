#include <iostream>

using namespace std;

int main()
{
	int tests, casenr = 0;
	cin >> tests;

	while (tests--)
	{
		int walls;
		cin >> walls;

		int prev = -1, low = 0, high = 0, temp;

		for (int i = 0; i < walls; i++)
		{
			cin >> temp;

			if (prev == -1)
				prev = temp;
			else
			{
				if (temp > prev)
					high++;
				else if (temp < prev)
					low++;
				prev = temp;
			}
		}

		cout << "Case " << ++casenr << ": " << high << " " << low << endl;
	}

	return 0;
}