#include <math.h>
#include <stdio.h>

int main()
{
	double surface, n, pi = 2.0 * acos(0);
	int cases = 0;

	while (1)
	{
		scanf("%lf %lf", &n, &surface);
		if (n < 3.0)
			break;

		double pr = (pi * surface) / (n * tan(pi / n));
		double pR = (2 * surface * pi) / (n * sin((pi * 2) / n));
		double fans = pR - surface;
		double judges = surface - pr;

		printf("Case %d: %.5f %.5f\n", ++cases, fans, judges);
	}

	return 0;
}