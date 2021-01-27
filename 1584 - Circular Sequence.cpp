#include <iostream>

std::string sequence(std::string input, int x)
{
	std::string s = "";

	for (unsigned int i = 0; i < input.length(); i++)
	{
		s += input[(x + i) % input.length()];
	}

	return s;
}

int main()
{
	int tests;
	std::cin >> tests;

	while (tests--)
	{
		std::string input;
		std::cin >> input;

		std::string min = input;

		for (unsigned int i = 1; i < input.length(); i++)
		{
			std::string seq = sequence(input, i);

			if (std::lexicographical_compare(seq.begin(), seq.end(), min.begin(), min.end()))
			{
				min = seq;
			}
		}

		std::cout << min << std::endl;
	}
}