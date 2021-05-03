#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Point
{
	double x;
	double y;

	Point()
	{
		x = 0;
		y = 0;
	}

	Point(double _x, double _y)
	{
		x = _x;
		y = _y;
	}

	bool operator<(const Point &p) const
	{
		if (x != p.x)
		{
			return x < p.x;
		}

		return y < p.y;
	}
};

class Figure
{
public:
	virtual void Check(Point &p, bool &result) = 0;
};

class Rectangle : public Figure
{
public:
	Rectangle(string line);
	void Check(Point &p, bool &result);

private:
	Point p1;
	Point p2;
};

class Triangle : public Figure
{
public:
	Triangle(string line);
	void Check(Point &p, bool &result);

private:
	Point p1;
	Point p2;
	Point p3;
	vector<Point> points;
};

class Circle : public Figure
{
public:
	Circle(string line);
	void Check(Point &p, bool &result);

	Point p;
	double r;
};

Rectangle::Rectangle(string line)
{
	char t;
	double x1, x2, y1, y2;
	stringstream s;

	s << line;
	s >> t >> x1 >> y1 >> x2 >> y2;

	p1 = Point(x1, y1);
	p2 = Point(x2, y2);
}

void Rectangle::Check(Point &p, bool &result)
{
	if (p2 < p1)
	{
		swap(p1, p2);
	}

	if ((((p.x > p1.x) && (p.x < p2.x)) && ((p.y > p1.y) && (p.y < p2.y))) || (((p.x > p1.x) && (p.x < p2.x)) && ((p.y < p1.y) && (p.y > p2.y))))
	{
		result = true;
		return;
	}

	result = false;
}

Triangle::Triangle(string line)
{
	char t;
	double x1, x2, x3, y1, y2, y3;
	stringstream s;

	s << line;
	s >> t >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	p1 = Point(x1, y1);
	p2 = Point(x2, y2);
	p3 = Point(x3, y3);

	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);

	sort(points.begin(), points.end());
}

void Triangle::Check(Point &p, bool &result)
{
	bool in = 0;
	int n = 3;

	for (int i = 0, j = n - 1; i < n; j = i++)
	{
		if ((points[i].y <= p.y && p.y < points[j].y) || (points[j].y <= p.y && p.y < points[i].y))
		{
			if (p.x < (points[j].x - points[i].x) * (p.y - points[i].y) * 1.0 / (points[j].y - points[i].y) + points[i].x)
			{
				in ^= 1;
			}
		}
	}

	result = in;
}

Circle::Circle(string line)
{
	char t;
	double x1, y1, _r;
	stringstream s;

	s << line;
	s >> t >> x1 >> y1 >> _r;

	p = Point(x1, y1);
	r = _r;
}

void Circle::Check(Point &p, bool &result)
{
	if ((pow(p.x - this->p.x, 2) + pow(p.y - this->p.y, 2)) < r * r)
	{
		result = true;
		return;
	}

	result = false;
}

int main()
{
	vector<Point> points;
	vector<Figure *> figures;

	int mode = 1;
	string line;

	while (getline(cin, line))
	{
		if (line.length() > 0 && line[0] == '*')
		{
			mode = 2;
			continue;
		}

		if (mode == 1)
		{
			switch (line[0])
			{
			case 'r':
			{
				Figure *r = new Rectangle(line);
				figures.push_back(r);
			}
			break;
			case 't':
			{
				Figure *t = new Triangle(line);
				figures.push_back(t);
			}
			break;
			case 'c':
			{
				Figure *c = new Circle(line);
				figures.push_back(c);
			}
			break;
			}
		}
		else if (mode == 2)
		{
			double x, y;
			stringstream s;

			s << line;
			s >> x >> y;

			if (x == 9999.9 && y == 9999.9)
			{
				break;
			}

			Point point(x, y);
			points.push_back(point);
		}
	}

	bool result;

	for (unsigned int i = 0; i < points.size(); i++)
	{
		bool ok = false;
		for (unsigned int j = 0; j < figures.size(); j++)
		{
			figures[j]->Check(points[i], result);

			if (result)
			{
				cout << "Point " << i + 1 << " is contained in figure " << j + 1 << endl;
				ok = true;
			}
		}

		if (!ok)
		{
			cout << "Point " << i + 1 << " is not contained in any figure" << endl;
		}
	}

	return 0;
}