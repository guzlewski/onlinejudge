#include <iostream>
#include <vector>

using namespace std;

struct Drink
{
	string name;

	vector<string> strongerThan;

	Drink(string n)
	{
		name = n;
	}
};

Drink* Find(vector<Drink>& drinks, string name)
{
	for (unsigned int i = 0; i < drinks.size(); i++)
	{
		if (drinks[i].name == name)
		{
			return &drinks[i];
		}
	}

	return NULL;
}

int main()
{
	int drinkCount, caseNr = 0;

	while (cin >> drinkCount)
	{
		vector<Drink> drinks;

		for (int i = 0; i < drinkCount; i++)
		{
			string name;
			cin >> name;

			drinks.push_back(Drink(name));
		}

		int count;
		cin >> count;

		for (int i = 0; i < count; i++)
		{
			string light, strong;
			cin >> light >> strong;

			Find(drinks, strong)->strongerThan.push_back(Find(drinks, light)->name);
		}

		cout << "Case #" << ++caseNr << ": Dilbert should drink beverages in this order:";

		int good = 0;
		unsigned int i;

		while (good != drinkCount)
		{
			string name;

			for (i = 0; i < drinks.size(); i++)
			{
				if (drinks[i].strongerThan.size() == 0)
				{
					cout << " " << drinks[i].name;
					name = drinks[i].name;
					break;
				}
			}

			drinks.erase(drinks.begin() + i);

			for (i = 0; i < drinks.size(); i++)
			{
				for (unsigned int j = 0; j < drinks[i].strongerThan.size(); j++)
				{
					if (drinks[i].strongerThan[j] == name)
					{
						drinks[i].strongerThan.erase(drinks[i].strongerThan.begin() + j);
						j--;
					}
				}
			}

			good++;
		}

		cout << "." << endl << endl;

	}

	return 0;
}