#include <cmath>
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	int tests;
	cin >> tests;

	while (tests--)
	{
		int n, k;
		cin >> n >> k;

		int mod = pow(10, n);

		long long result = k;
		unordered_map<int, int> hashtable;
		unordered_map<int, int>::iterator it;

		hashtable[result] = 1;

		while (true)
		{
			result *= result;

			while (result >= mod)
			{
				result /= 10;
			}

			if (hashtable.find(result) != hashtable.end())
			{
				break;
			}

			hashtable[result] = 1;
		}

		result = 0;

		for (it = hashtable.begin(); it != hashtable.end(); it++)
		{
			if (it->first > result)
			{
				result = it->first;
			}
		}

		cout << result << endl;
	}

	return 0;
}