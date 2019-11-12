#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

using namespace std;

int main()
{
	while (true)
	{
		string hex;
		cin >> hex;
		if (hex == "-1") return 0;
		if (hex == "0")
		{
			cout << "0x0" << endl;
			continue;
		}

		int temp = atoi(hex.c_str());
		if (temp == 0)
		{
			cout << hex2dec(hex) << endl;
		}
		else
		{
			cout << dec2hex(temp) << endl;
		}
	}

	return 0;
}
