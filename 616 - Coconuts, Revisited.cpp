#include <iostream>

using namespace std;

int main()
{
	int coconuts;

	while (true)
	{
		cin >> coconuts;
		if (coconuts < 0)
			break;

		if (coconuts < 2)
		{
			cout << coconuts << " coconuts, no solution" << endl;
			continue;
		}
		else
		{
			bool done = false;
			int start = coconuts - 1;
			if (start > 20)
				start = 20;

			for (int people = start; people > 1; people--)
			{
				int temp = coconuts;
				if (temp % people > 1)
					continue;

				bool ok = true;
				for (int i = 0; i < people; i++)
				{
					--temp;
					if (temp % people != 0)
					{
						ok = false;
						break;
					}

					temp = temp - (temp / people);
				}
				if (temp % people != 0)
					ok = false;

				if (ok)
				{
					cout << coconuts << " coconuts, " << people << " people and 1 monkey" << endl;
					done = true;
					break;
				}
			}

			if (!done)
				cout << coconuts << " coconuts, no solution" << endl;
		}
	}

	return 0;
}