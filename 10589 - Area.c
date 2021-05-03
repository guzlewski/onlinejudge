#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n, a, i;
	while (1)
	{
		scanf("%d %d", &n, &a);
		if (n == 0)
			break;

		int inside, outside;
		inside = 0;
		outside = 0;

		for (i = 1; i <= n; i++)
		{
			double x, y;
			scanf("%lf %lf", &x, &y);

			int counter = 0;

			if (sqrt((0 - x) * (0 - x) + (0 - y) * (0 - y)) < a)
				counter++;
			if (sqrt((0 - x) * (0 - x) + (a - y) * (a - y)) < a)
				counter++;
			if (sqrt((a - x) * (a - x) + (0 - y) * (0 - y)) < a)
				counter++;
			if (sqrt((a - x) * (a - x) + (a - y) * (a - y)) < a)
				counter++;
			if (counter == 4)
				inside++;
			else
				outside++;
		}
		double r;
		r = ((double)inside * a * a) / ((double)n);
		printf("%.5f\n", r);
	}
	return 0;
}