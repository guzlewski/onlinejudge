#include <iostream>
#include <vector>
using namespace std;

class Rational
{
public:
	Rational();
	Rational(int numerator, int denominator = 1);
	Rational(const Rational& r);

	Rational operator+(Rational& r);
	Rational operator-(Rational& r);
	Rational operator*(Rational& r);
	Rational operator/(Rational& r);

	friend bool operator==(Rational& r1, Rational& r2);
	friend bool operator!=(Rational& r1, Rational& r2);
	friend bool operator<(Rational& r1, Rational& r2);
	friend bool operator>(Rational& r1, Rational& r2);
	friend bool operator<=(Rational& r1, Rational& r2);
	friend bool operator>=(Rational& r1, Rational& r2);

	friend ostream& operator<<(ostream& output, Rational& r);
	friend istream& operator>>(istream& input, Rational& r);

	void shorten();

	int getnumerator();
	int getdenominator();

private:
	int numerator;
	int denominator;

	static int gcd(int x, int y);
};

Rational::Rational() {
	numerator = 0;
	denominator = 1;
}

Rational::Rational(const Rational& r) {
	this->numerator = r.numerator;
	this->denominator = r.denominator;
}

Rational::Rational(int numerator, int denominator) {
	this->numerator = numerator;
	this->denominator = denominator;

	shorten();
}

Rational Rational::operator+(Rational& r)
{
	int nww = (this->denominator * r.denominator) / gcd(this->denominator, r.denominator);
	int w1 = nww / this->denominator, w2 = nww / r.denominator;

	return  Rational(w1 * this->numerator + w2 * r.numerator, nww);
}

Rational Rational::operator-(Rational& r)
{
	int nww = (this->denominator * r.denominator) / gcd(this->denominator, r.denominator);
	int w1 = nww / this->denominator, w2 = nww / r.denominator;

	return Rational(w1 * this->numerator - w2 * r.numerator, nww);
}

Rational Rational::operator*(Rational& r)
{
	return Rational(this->numerator * r.numerator, this->denominator * r.denominator);
}

Rational Rational::operator/(Rational& r)
{
	return  Rational(this->numerator * r.denominator, this->denominator * r.numerator);
}

inline int Rational::getnumerator()
{
	return this->numerator;
}

inline int Rational::getdenominator()
{
	return this->denominator;
}

int Rational::gcd(int x, int y) {
	while (y != 0) {
		int r = x % y;
		x = y;
		y = r;
	}

	return x;
}

void Rational::shorten() {
	int _gcd = gcd(this->numerator, this->denominator);

	this->numerator /= _gcd;
	this->denominator /= _gcd;

	if (this->denominator < 0)
	{
		this->denominator = 0 - this->denominator;
		this->numerator = 0 - this->numerator;
	}
}

bool operator==(Rational& r1, Rational& r2)
{
	return (r1.denominator == r2.denominator) && (r1.numerator == r2.numerator);
}

bool operator!=(Rational& r1, Rational& r2)
{
	return (r1.denominator != r2.denominator) || (r1.numerator != r2.numerator);
}

bool operator>(Rational& r1, Rational& r2)
{
	Rational x = r1 - r2;
	if (((double)x.getnumerator() / (double)x.getdenominator()) > 0) return true;
	else return false;
}

bool operator<(Rational& r1, Rational& r2)
{
	Rational x = r1 - r2;
	if (((double)x.getnumerator() / (double)x.getdenominator()) < 0) return true;
	else return false;
}

bool operator>=(Rational& r1, Rational& r2)
{
	Rational x = r1 - r2;
	if (((double)x.getnumerator() / (double)x.getdenominator()) >= 0) return true;
	else return false;
}

bool operator<=(Rational& r1, Rational& r2)
{
	Rational x = r1 - r2;
	if (((double)x.getnumerator() / (double)x.getdenominator()) <= 0) return true;
	else return false;
}

ostream& operator<<(ostream& output, Rational& r) {
	output << r.numerator;

	if (r.denominator != 1)
		output << "|" << r.denominator;

	return output;
}

istream& operator>>(istream& input, Rational& r) {
	char separator;
	input >> r.numerator >> separator >> r.denominator;
	r.shorten();

	return input;
}

int main()
{
	int numerator, denomirator;

	while (cin >> numerator >> denomirator)
	{
		vector<int> numbers;

		while (true)
		{
			if (numerator % denomirator == 0) break;

			numbers.push_back(numerator / denomirator);

			int t = numerator;
			numerator = denomirator;
			denomirator = t % denomirator;
		}

		numbers.push_back(numerator);

		cout << "[" << numbers[0] << ";";

		for (unsigned int i = 1; i < numbers.size(); i++)
		{
			cout << numbers[i];

			if (i + 1 != numbers.size()) cout << ",";
		}

		cout << "]" << endl;
	}

	return 0;
}