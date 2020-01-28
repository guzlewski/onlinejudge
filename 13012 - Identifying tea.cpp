#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int type;

	while (cin >> type)
	{
		int correct = 0;

		for (int i = 0; i < 5; i++)
		{
			int guess;
			cin >> guess;

			if (guess == type)
			{
				correct++;
			}
		}

		cout << correct << endl;
	}

	return 0;
}