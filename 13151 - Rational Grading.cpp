#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int n, m;
	string s;

	while (true)
	{
		cin >> s >> m;

		if (s == "0" && m == 0)
			break;

		if (s[0] == '0' && s[1] == 'x') 
			sscanf(s.c_str(), "%X", &n);
		else if (s[0] == '0') 
			sscanf(s.c_str(), "%o", &n);
		else 
			sscanf(s.c_str(), "%d", &n);

		int ret = 0, val;
		for (int i = 0; i < m; i++)
		{
			string cmd;
			cin >> cmd >> val;

			if (!strcmp(cmd.c_str(), "i"))
			{
				if (val != n) 
					n = val;
				else 
					ret++;
			}
			else if (!strcmp(cmd.c_str(), "i++"))
			{
				if (val != n) 
					n = val;
				else 
					ret++;

				n++;
			}
			else if (!strcmp(cmd.c_str(), "i--"))
			{
				if (val != n) 
					n = val;
				else 
					ret++;

				n--;
			}
			else if (!strcmp(cmd.c_str(), "++i"))
			{
				++n;

				if (val != n) 
					n = val;
				else 
					ret++;
			}
			else if (!strcmp(cmd.c_str(), "--i"))
			{
				--n;

				if (val != n) 
					n = val;
				else 
					ret++;
			}
		}

		cout << ret << endl;
	}
	return 0;
}