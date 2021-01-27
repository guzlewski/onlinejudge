#include <iostream>
#include <cstring>
#include <queue>

#define EMPTY 0
#define UNKNOWN -1
#define FILL -2
#define NOTFILL -3
#define PROCESSING -4

struct node
{
	int row;
	int column;

	node()
	{
		row = 0;
		column = 0;
	};

	node(int _row, int _column)
	{
		row = _row;
		column = _column;
	};

	~node() {};
};

void floodFill(int i, int j, int m, int n, int* tab)
{
	std::queue<node> toProcess, processed;
	toProcess.push(node(i, j));

	bool open = false;

	while (!toProcess.empty())
	{
		node item = toProcess.front();
		toProcess.pop();

		tab[item.row * n + item.column] = PROCESSING;

		if (item.row == 0 || item.row + 1 == m || item.column == 0 || item.column + 1 == n)
		{
			open = true;
		}

		if (item.column != 0 && tab[item.row * n + item.column - 1] == UNKNOWN)
		{
			toProcess.push(node(item.row, item.column - 1));
		}

		if (item.column + 1 < n && tab[item.row * n + item.column + 1] == UNKNOWN)
		{
			toProcess.push(node(item.row, item.column + 1));
		}

		if (item.row != 0 && tab[(item.row - 1) * n + item.column] == UNKNOWN)
		{
			toProcess.push(node(item.row - 1, item.column));
		}

		if (item.row + 1 < m && tab[(item.row + 1) * n + item.column] == UNKNOWN)
		{
			toProcess.push(node(item.row + 1, item.column));
		}

		processed.push(item);
	}

	while (!processed.empty())
	{
		node item = processed.front();
		processed.pop();

		if (open)
		{
			tab[item.row * n + item.column] = NOTFILL;
		}
		else
		{
			tab[item.row * n + item.column] = FILL;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	int n, m;

	while (std::cin >> m >> n && n != 0 && m != 0)
	{
		int* tab = new int[m * n];
		int height = 3 * m + 1, width = 5 * n + 1;
		char* output = new char[width * height];

		memset(output, (int)' ', width * height * sizeof(char));

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int temp;
				std::cin >> temp;

				if (temp == 1)
				{
					tab[i * n + j] = UNKNOWN;
				}
				else
				{
					for (int k = 0; k < 6; k++)
					{
						output[i * width * 3 + k + 5 * j] = '+';
						output[i * width * 3 + 3 * width + k + 5 * j] = '+';
					}

					for (int k = 0; k < 4; k++)
					{
						output[i * width * 3 + k * width + 5 * j] = '+';
						output[i * width * 3 + k * width + 5 * j + 5] = '+';
					}

					tab[i * n + j] = EMPTY;
				}
			}
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (tab[i * n + j] == UNKNOWN)
				{
					floodFill(i, j, m, n, tab);
				}
			}
		}


		int index = 0;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (tab[i * n + j] == EMPTY)
				{
					if ((i + 1 < m && tab[(i + 1) * n + j] == EMPTY && (i == 0 || tab[(i - 1) * n + j] != EMPTY)) || (j + 1 < n && tab[i * n + j + 1] == EMPTY && (j == 0 || tab[i * n + j - 1] != EMPTY)))
					{
						++index;

						output[i * width * 3 + 1 * width + 1 + 5 * j] = '0' + index / 100;
						output[i * width * 3 + 1 * width + 2 + 5 * j] = '0' + (index / 10) % 10;
						output[i * width * 3 + 1 * width + 3 + 5 * j] = '0' + index % 10;
					}
				}
				else if (tab[i * n + j] == FILL)
				{
					for (int k = 0; k < 6; k++)
					{
						output[i * width * 3 + 0 * width + k + 5 * j] = '+';
						output[i * width * 3 + 1 * width + k + 5 * j] = '+';
						output[i * width * 3 + 2 * width + k + 5 * j] = '+';
						output[i * width * 3 + 3 * width + k + 5 * j] = '+';
					}
				}
			}
		}

		for (int i = 0; i < height; i++)
		{
			for (int j = width - 1; j >= 0; j--)
			{
				if (output[i * width + j] != ' ')
				{
					break;
				}

				output[i * width + j] = 0;
			}
		}

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (output[i * width + j] == 0)
				{
					break;
				}

				std::cout << output[i * width + j];
			}

			std::cout << std::endl;
		}

		std::cout << std::endl;

		delete[] tab;
		delete[] output;
	}
}