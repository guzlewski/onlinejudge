#include <iostream>

int main()
{
	int h, w;

	while (std::cin >> h >> w)
	{
		int area = 0;

		for (int i = 0; i < h; i++)
		{
			std::string line;
			std::cin >> line;

			bool inside = false;

			for (int i = 0; i < w; i++)
			{
				if (line[i] == '.' && inside)
				{
					area++;
				}
				else if (line[i] != '.')
				{
					if (inside)
					{
						inside = false;
						area++;
					}
					else
					{
						inside = true;
					}
				}
			}
		}

		std::cout << area << std::endl;
	}
}
