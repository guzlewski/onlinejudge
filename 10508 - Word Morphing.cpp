#include <iostream>
#include <vector>

using namespace std;

int CalculateDifference(string input, string _template)
{
	int count = 0;
	for (int i = 0; i < input.size(); i++)
		if (input[i] != _template[i])
			count++;

	return count;
}

int main()
{
	int word, len;
	string x;

	while (cin >> word >> len)
	{
		vector<string> words(word);

		cin >> x;
		words[0] = x;

		cin >> x;
		words[word - 1] = x;

		for (int i = 1; i < word - 1; i++)
		{
			cin >> x;
			words[CalculateDifference(x, words[0])] = x;
		}

		for (int i = 0; i < words.size(); i++)
			cout << words[i] << endl;
	}

	return 0;
}