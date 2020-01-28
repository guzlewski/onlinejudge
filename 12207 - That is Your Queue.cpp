#include <iostream>
#include <list>

using namespace std;

class EmergencyQueue
{
private:
	list<int> pepole;

public:
	EmergencyQueue(int population)
	{
		for (int i = 1; i <= population; i++)
		{
			pepole.push_back(i);
		}
	}

	int Next()
	{
		int person = pepole.front();
		pepole.pop_front();
		pepole.push_back(person);

		return person;
	}

	void Emegency(int person)
	{
		pepole.remove(person);
		pepole.push_front(person);
	}
};

int main()
{
	int population, commnands, caseN = 0;

	while (true)
	{
		cin >> population >> commnands;
		if (population == 0 && commnands == 0) break;

		cout << "Case " << ++caseN << ":" << endl;

		EmergencyQueue em = EmergencyQueue(min(commnands, population));
		char command;

		for (int i = 0; i < commnands; i++)
		{
			cin >> command;
			if (command == 'E')
			{
				int inx;
				cin >> inx;
				em.Emegency(inx);
			}
			else cout << em.Next() << endl;
		}
	}

	return 0;
}