#include <iostream>

#define SIZE 1299709 + 1
bool composite[SIZE];

void seedPimes()
{
    for (int i = 2; i * i < SIZE; i++)
    {
        if (composite[i])
        {
            continue;
        }

        for (int j = i * i; j < SIZE; j += i)
        {
            composite[j] = true;
        }
    }
}

int main()
{
    seedPimes();

    int number;
    while (std::cin >> number && number != 0)
    {
        if (!composite[number])
        {
            std::cout << 0 << std::endl;
            continue;
        }

        int up = SIZE, down = 0;

        for (int i = number - 1; i >= 0; i--)
        {
            if (!composite[i])
            {
                down = i;
                break;
            }
        }

        for (int i = number + 1; i < SIZE; i++)
        {
            if (!composite[i])
            {
                up = i;
                break;
            }
        }

        std::cout << up - down << std::endl;
    }
}