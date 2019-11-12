#include <stdio.h>
#include <stdlib.h>

struct Line
{
	int a;
	int b;
	int c;
};

int main()
{
	while (1)
	{
		struct Line f, g;
		scanf("%d %d %d", &f.a, &f.b, &f.c);
		scanf("%d %d %d", &g.a, &g.b, &g.c);

		if (f.a == 0 && f.b == 0 && f.c == 0 && g.a == 0 && g.b == 0 && g.c == 0) break;

		int det = f.a * g.b - g.a * f.b;
		if (det == 0) printf("No fixed point exists.\n");
		else
		{
			float x, y;
			x = ((float)(f.c * g.b - g.c * f.b)) / (float)det;
			y = ((float)(f.a * g.c - g.a * f.c)) / (float)det;

			printf("The fixed point is at %.2f %.2f.\n", x, y);
		}
	}

	return 0;
}