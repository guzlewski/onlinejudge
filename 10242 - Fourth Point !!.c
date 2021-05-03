#include <stdio.h>
#include <stdlib.h>

struct Point
{
	double x;
	double y;
};

int Compare(struct Point x, struct Point y)
{
	if (x.x == y.x && x.y == y.y)
		return 1;
	return 0;
}

int main()
{
	struct Point a, b, c, d, e, f, mid, center, fourth;
	while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y) != EOF)
	{
		if (Compare(a, b) == 1)
		{
			mid = a;
			e = c;
			f = d;
		}
		else if (Compare(a, c) == 1)
		{
			mid = a;
			e = b;
			f = d;
		}
		else if (Compare(a, d) == 1)
		{
			mid = a;
			e = b;
			f = c;
		}
		else if (Compare(b, c) == 1)
		{
			mid = b;
			e = a;
			f = d;
		}
		else if (Compare(b, d) == 1)
		{
			mid = b;
			e = a;
			f = c;
		}
		else
		{
			mid = c;
			e = a;
			f = b;
		}

		center.x = (e.x + f.x) / 2.0;
		center.y = (e.y + f.y) / 2.0;

		fourth.x = ((2.0 * center.x) - mid.x);
		fourth.y = ((2.0 * center.y) - mid.y);

		printf("%.*lf ", 3, fourth.x);
		printf("%.*lf\n", 3, fourth.y);
	}
	return 0;
}