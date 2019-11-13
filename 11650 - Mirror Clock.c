#include <stdio.h>
#include <stdlib.h>

int main()
{
	int tests, time, hour, minute;

	scanf("%d", &tests);

	while (tests--)
	{
		scanf("%d:%d", &hour, &minute);

		time = 12 * 60 - (hour * 60 + minute);
		hour = 0;
		minute = time % 60;

		if (time >= 0)
		{
			while (time >= 60)
			{
				hour++;
				time = time - 60;
			}
			if (hour == 0) hour = 12;
		}
		else
		{
			hour = 12;
			while (time < 60)
			{
				hour--;
				time = time + 60;
			}
			if (minute != 0) hour++;
		}

		if (minute < 0) minute += 60;

		printf("%0.2d:%0.2d\n", hour, minute);
	}

	return 0;
}