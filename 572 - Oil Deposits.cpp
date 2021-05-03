#include <iostream>
#include <vector>

using namespace std;

int oil = 0;

void Check(vector<vector<char>> &fields, int m, int n, int add)
{
	if (m < 0 || m >= (int)fields.size() || n < 0 || n >= (int)fields[0].size() || fields[m][n] != '@')
	{
		return;
	}

	fields[m][n] = '*';

	if (add)
	{
		oil++;
	}

	Check(fields, m - 1, n + 1, 0);
	Check(fields, m - 1, n, 0);
	Check(fields, m - 1, n - 1, 0);

	Check(fields, m, n - 1, 0);
	Check(fields, m, n + 1, 0);

	Check(fields, m + 1, n - 1, 0);
	Check(fields, m + 1, n, 0);
	Check(fields, m + 1, n + 1, 0);
}

int main()
{
	while (true)
	{
		int n, m;
		cin >> m >> n;

		if (m == 0 || n == 0)
		{
			break;
		}

		vector<vector<char>> fields(m);

		for (int i = 0; i < m; i++)
		{
			string temp;
			cin >> temp;

			for (int j = 0; j < n; j++)
			{
				fields[i].push_back(temp[j]);
			}
		}

		oil = 0;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				Check(fields, i, j, 1);
			}
		}

		cout << oil << endl;
	}

	return 0;
}