#include <iostream>

using namespace std;

class Matrix
{
public:
	Matrix(int n);
	~Matrix();

	void Increment();
	void Decrement();
	void Transpose();
	void SwapRow(int a, int b);
	void SwapCol(int a, int b);

	friend ostream& operator<<(ostream& output, Matrix& r);
	friend istream& operator>>(istream& input, Matrix& m);

private:
	int n;
	int** tab;
};

Matrix::Matrix(int n)
{
	this->n = n;
	tab = new int* [n];

	for (int i = 0; i < n; ++i)
		tab[i] = new int[n];
}

Matrix::~Matrix()
{
	for (int i = 0; i < n; ++i)
		delete[] tab[i];

	delete[] tab;
}

void Matrix::Increment()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tab[i][j] = (tab[i][j] + 1) % 10;
}

void Matrix::Decrement()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			tab[i][j] = (tab[i][j] - 1) % 10;
			if (tab[i][j] < 0) tab[i][j] += 10;
		}
}

void Matrix::Transpose()
{
	Matrix temp(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			temp.tab[i][j] = tab[j][i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tab[i][j] = temp.tab[i][j];
}

void Matrix::SwapRow(int a, int b)
{
	int temp[n];

	for (int i = 0; i < n; i++)
		temp[i] = tab[a][i];

	for (int i = 0; i < n; i++)
	{
		tab[a][i] = tab[b][i];
		tab[b][i] = temp[i];
	}
}

void Matrix::SwapCol(int a, int b)
{
	int temp[n];

	for (int i = 0; i < n; i++)
		temp[i] = tab[i][a];

	for (int i = 0; i < n; i++)
	{
		tab[i][a] = tab[i][b];
		tab[i][b] = temp[i];
	}
}

ostream& operator<<(ostream& output, Matrix& m)
{
	for (int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.n; j++)
			output << m.tab[i][j];

		cout << endl;
	}

	return output;
}

istream& operator>>(istream& input, Matrix& m)
{
	char c;
	for (int i = 0; i < m.n; i++)
		for (int j = 0; j < m.n; j++)
		{
			input >> c;
			m.tab[i][j] = c - '0';
		}

	return input;
}

int main()
{
	string command;
	int tests, n, m, casenr = 0;
	cin >> tests;

	while (tests--)
	{
		cin >> n;
		Matrix tab(n);

		cin >> tab >> m;

		for (int i = 0; i < m; i++)
		{
			cin >> command;

			if (command == "inc")
				tab.Increment();
			else if (command == "dec")
				tab.Decrement();
			else if (command == "row" || command == "col")
			{
				int a, b;
				cin >> a >> b;

				a--;
				b--;

				if (command == "row")
					tab.SwapRow(a, b);
				else
					tab.SwapCol(a, b);
			}
			else if (command == "transpose")
				tab.Transpose();
		}

		cout << "Case #" << ++casenr << endl << tab << endl;
	}

	return 0;
}