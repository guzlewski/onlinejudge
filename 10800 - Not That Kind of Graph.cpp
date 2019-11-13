#include <iostream>

using namespace std;

int main()
{
	int tests, casenr = 0;
	cin >> tests;

	while (tests--)
	{
		string data;
		cin >> data;

		char tab[110][60];

		for (int i = 0; i < 110; i++)
			for (int j = 0; j < 60; j++)
				tab[i][j] = ' ';

		int index = 55;
		for (unsigned int i = 0; i < data.length(); i++)
		{
			if (data[i] == 'R')
			{
				if (i > 0 && data[i - 1] == 'R') index--;
				tab[index][i] = '/';
			}
			else if (data[i] == 'F')
			{
				if (i > 0 && (data[i - 1] == 'F' || data[i - 1] == 'C')) index++;
				tab[index][i] = '\\';
			}
			else
			{
				if (i > 0 && data[i - 1] == 'R') index--;
				tab[index][i] = '_';
			}
		}

		for (int i = 0; i < 110; i++)
		{
			int d = 0;
			for (int j = 0; j < 60; j++)
				if (tab[i][j] != ' ') d = j + 1;
			tab[i][d] = '\0';
		}

		cout << "Case #" << ++casenr << ":" << endl;

		for (int i = 0; i < 110; i++)
		{
			if (tab[i][0] == '\0') continue;

			cout << "| ";

			for (int j = 0; j < 60; j++)
			{
				if (tab[i][j] == '\0') break;
				cout << tab[i][j];
			}
			cout << endl;
		}

		cout << '+';
		for (unsigned int i = 0; i < data.length() + 2; i++)
			cout << '-';
		cout << endl;

		cout << endl;
	}
}