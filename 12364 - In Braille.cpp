#include <iostream>

void init_screen(char *screen, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j + 1 != width)
            {
                screen[i * width + j] = '.';
            }
            else
            {
                screen[i * width + j] = '\0';
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 2; j < width; j += 3)
        {
            if (screen[i * width + j] != '\0')
            {
                screen[i * width + j] = ' ';
            }
        }
    }
}

void n2b(char digit, char *top, char *mid, char *bot)
{
    switch (digit)
    {
    case '1':
        top[0] = '*';
        break;
    case '2':
        top[0] = mid[0] = '*';
        break;
    case '3':
        top[0] = top[1] = '*';
        break;
    case '4':
        top[0] = top[1] = mid[1] = '*';
        break;
    case '5':
        top[0] = mid[1] = '*';
        break;
    case '6':
        top[0] = top[1] = mid[0] = '*';
        break;
    case '7':
        top[0] = top[1] = mid[0] = mid[1] = '*';
        break;
    case '8':
        top[0] = mid[0] = mid[1] = '*';
        break;
    case '9':
        top[1] = mid[0] = '*';
        break;
    case '0':
        top[1] = mid[0] = mid[1] = '*';
        break;
    default:
        break;
    }
}

void n2b(int d)
{
    std::string number;
    std::cin >> number;

    const int height = 3, width = 3 * d;

    char screen[height * width];
    init_screen(screen, height, width);

    size_t index = 0;
    for (int i = 0; i < d; i++)
    {
        n2b(number[i], &screen[0 * width + index], &screen[1 * width + index], &screen[2 * width + index]);
        index += 3;
    }
    std::cout << &screen[0 * width] << std::endl
              << &screen[1 * width] << std::endl
              << &screen[2 * width] << std::endl;
}

char b2n(char *top, char *mid, char *bot)
{
    if (top[0] == '*' && top[1] == '.' && mid[0] == '.' && mid[1] == '.')
    {
        return '1';
    }
    else if (top[0] == '*' && top[1] == '.' && mid[0] == '*' && mid[1] == '.')
    {
        return '2';
    }
    else if (top[0] == '*' && top[1] == '*' && mid[0] == '.' && mid[1] == '.')
    {
        return '3';
    }
    else if (top[0] == '*' && top[1] == '*' && mid[0] == '.' && mid[1] == '*')
    {
        return '4';
    }
    else if (top[0] == '*' && top[1] == '.' && mid[0] == '.' && mid[1] == '*')
    {
        return '5';
    }
    else if (top[0] == '*' && top[1] == '*' && mid[0] == '*' && mid[1] == '.')
    {
        return '6';
    }
    else if (top[0] == '*' && top[1] == '*' && mid[0] == '*' && mid[1] == '*')
    {
        return '7';
    }
    else if (top[0] == '*' && top[1] == '.' && mid[0] == '*' && mid[1] == '*')
    {
        return '8';
    }
    else if (top[0] == '.' && top[1] == '*' && mid[0] == '*' && mid[1] == '.')
    {
        return '9';
    }
    else if (top[0] == '.' && top[1] == '*' && mid[0] == '*' && mid[1] == '*')
    {
        return '0';
    }

    return '?';
}

void b2n(int d)
{
    std::string top, mid, bot, output = "";
    std::getline(std::cin, top);
    std::getline(std::cin, top);
    std::getline(std::cin, mid);
    std::getline(std::cin, bot);

    int index = 0;
    for (int i = 0; i < d; i++)
    {
        output += b2n(&top[index], &mid[index], &bot[index]);
        index += 3;
    }

    std::cout << output << std::endl;
}

int main()
{
    int d;
    char mode;

    while (std::cin >> d >> mode && d)
    {
        if (mode == 'S')
        {
            n2b(d);
        }
        else
        {
            b2n(d);
        }
    }

    return 0;
}