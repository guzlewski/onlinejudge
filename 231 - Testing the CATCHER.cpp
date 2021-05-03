#include <iostream>

using namespace std;

int main()
{
	int numbers = 0, caseN = 0, input[1000] = {0};

	int x;
	while (cin >> x)
	{
		if (x < 0)
			break;
		input[0] = x;
		numbers = 1;

		while (cin >> x)
		{
			input[numbers] = x;
			if (x < 0)
				break;
			numbers++;
		}

		int m[1000] = {0};
		for (int i = 0; i < numbers; i++)
		{
			for (int j = i + 1; j < numbers; j++)
			{
				if (m[j] < m[i] + 1 && input[j] < input[i])
					m[j] = m[i] + 1;
			}
		}

		int out = 0;
		for (int i = 0; i < numbers; i++)
		{
			if (out < m[i])
				out = m[i];
		}
		out++;

		if (caseN)
			cout << endl;
		cout << "Test #" << ++caseN << ":" << endl;
		cout << "  maximum possible interceptions: " << out << endl;
	}
	return 0;
}