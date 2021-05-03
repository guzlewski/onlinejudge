#include <iostream>
#include <bitset>

#define SIZE 1000000

bool isEmirp(std::bitset<SIZE> &primes, int n)
{
	int reversed = 0, temp = n;
	while (temp != 0)
	{
		reversed = reversed * 10 + temp % 10;
		temp /= 10;
	}

	return (reversed != n) && primes[reversed];
}

void init(std::bitset<SIZE> &primes)
{
	primes.set();
	primes[0] = false;
	primes[1] = false;

	for (size_t i = 2; i * i < primes.size(); i++)
	{
		if (!primes[i])
		{
			continue;
		}

		for (size_t j = 2 * i; j < primes.size(); j += i)
		{
			primes[j] = false;
		}
	}
}

int main()
{
	std::bitset<SIZE> primes;
	init(primes);

	int n;
	while (std::cin >> n)
	{
		if (!primes[n])
		{
			std::cout << n << " is not prime." << std::endl;
		}
		else if (isEmirp(primes, n))
		{
			std::cout << n << " is emirp." << std::endl;
		}
		else
		{
			std::cout << n << " is prime." << std::endl;
		}
	}
}