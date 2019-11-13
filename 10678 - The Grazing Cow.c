#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int tests;
	scanf("%d", &tests);

	double pi = 2 * acos(0), x1, x2, out;

	while (tests--)
	{
		scanf("%lf %lf", &x1, &x2);

		x1 /= 2;
		x2 /= 2;

		out = pi * x2 * sqrt(x2 * x2 - x1 * x1);
		printf("%0.3f\n", out);
	}

	return 0;
}