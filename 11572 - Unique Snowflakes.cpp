#include <iostream>
#include <map>

using namespace std;

int main()
{
	int tests;
	cin >> tests;

	while (tests--)
	{
		int n, i;
		cin >> n;

		map<int, int> lastSeen;
		int begin = 0, max = 0;

		for (i = 1; i <= n; i++)
		{
			int temp;
			cin >> temp;

			if (lastSeen[temp] > begin)
			{
				if (i - begin - 1 > max)
				{
					max = i - 1 - begin;
				}

				begin = lastSeen[temp];
			}

			lastSeen[temp] = i;
		}

		if (i - begin - 1 > max)
		{
			max = i - 1 - begin;
		}

		cout << max << endl;
	}

	return 0;
}