#include <iostream>
#include <cstring>

#define offset 536870912

int main()
{
	char partialsum[offset * 2];

	int tests;
	std::cin >> tests;

	while (tests--)
	{
		int n;
		std::cin >> n;

		memset(partialsum, 0, sizeof(partialsum));

		int *a = new int[n];
		int *b = new int[n];
		int *c = new int[n];
		int *d = new int[n];

		for (int i = 0; i < n; i++)
		{
			int ia, ib, ic, id;
			std::cin >> ia >> ib >> ic >> id;

			a[i] = ia;
			b[i] = ib;
			c[i] = ic;
			d[i] = id;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int sum = a[i] + b[j];

				if (sum < 0)
				{
					sum = std::abs(sum) + offset;
				}

				(*(partialsum + sum))++;
			}
		}

		int zeros = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int sum = c[i] + d[j];

				if (sum > 0)
				{
					sum += offset;
				}
				else
				{
					sum = std::abs(sum);
				}

				zeros += *(partialsum + sum);
			}
		}

		delete[] a;
		delete[] b;
		delete[] c;
		delete[] d;

		std::cout << zeros << std::endl;

		if (tests != 0)
		{
			std::cout << std::endl;
		}
	}
}
