#include <iostream>

int main()
{
    int size, set = 0;

    while (std::cin >> size && size)
    {
        std::cout << "Output for data set " << ++set << ", " << size << " bytes:" << std::endl;

        int downloaded = 0, speed = 0, time = 0;

        while (downloaded != size)
        {
            int chunk;
            std::cin >> chunk;

            downloaded += chunk;
            speed += chunk;
            time++;

            if (time % 5 == 0)
            {
                if (speed != 0)
                {
                    std::cout << "   Time remaining: " << ((5 * (size - downloaded)) + speed - 1) / speed << " seconds" << std::endl;
                }
                else
                {
                    std::cout << "   Time remaining: stalled" << std::endl;
                }

                speed = 0;
            }
        }

        std::cout << "Total time: " << time << " seconds" << std::endl
                  << std::endl;
    }

    return 0;
}