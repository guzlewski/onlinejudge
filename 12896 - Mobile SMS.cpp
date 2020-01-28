#include <iostream>

using namespace std;

string tab[] = { " ", ".,?\"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

int main()
{
	int tests;
	cin >> tests;

	while (tests--)
	{
		int length;
		cin >> length;

		int keys[length];

		for (int i = 0; i < length; i++)
		{
			cin >> keys[i];
		}

		for (int i = 0; i < length; i++)
		{
			int count;
			cin >> count;

			cout << tab[keys[i]][count - 1];
		}

		cout << endl;
	}

	return 0;
}