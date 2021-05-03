#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

#define SIZE 18001

void convert(int time)
{
    int h = time / 3600, m = (time / 60) % 60, s = time % 60;

    std::cout << std::setw(2) << std::setfill('0') << h << ":" << std::setw(2) << std::setfill('0') << m << ":" << std::setw(2) << std::setfill('0') << s << std::endl;
}

int main()
{
    while (true)
    {
        int time;
        std::cin >> time;

        if (time == 0)
        {
            break;
        }

        std::vector<int> times;
        times.push_back(time);

        while (std::cin >> time && time != 0)
        {
            times.push_back(time);
        }

        int timeline[SIZE], lights = times.size();
        memset(timeline, 0, SIZE * sizeof(int));

        for (auto &time : times)
        {
            for (int i = 0; i < SIZE; i += 2 * time)
            {
                for (int j = i; j < i + time - 5 && j < SIZE; j++)
                {
                    timeline[j]++;
                }
            }
        }

        bool found = false;

        for (int i = 2 * times[0]; i < SIZE; i++)
        {
            if (timeline[i] == lights)
            {
                convert(i);
                found = true;
                break;
            }
        }

        if (!found)
        {
            std::cout << "Signals fail to synchronise in 5 hours" << std::endl;
        }
    }

    return 0;
}