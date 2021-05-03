#include <iostream>
#include <vector>

bool fit(int size, std::string paragraphs[], int m, int x, int y)
{
    int xx = 0, yy = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < (int)paragraphs[i].size(); j++)
        {
            if (xx + size <= x)
            {
                xx += size;
            }
            else
            {
                for (int k = 0; j >= 0 && k <= x / size; j--, k++)
                {
                    if (paragraphs[i][j] == ' ')
                    {
                        break;
                    }
                }

                if (j < 0 || paragraphs[i][j] != ' ')
                {
                    return false;
                }

                xx = 0;
                yy += size;

                if (yy > y)
                {
                    return false;
                }
            }
        }

        xx = 0;
        yy += size;
    }

    if (yy > y)
    {
        return false;
    }

    return true;
}

int main()
{
    int n;
    std::cin >> n;

    while (n--)
    {
        int m;
        std::cin >> m;
        std::string paragraphs[m];

        std::getline(std::cin, paragraphs[0]);

        for (int i = 0; i < m; i++)
        {
            std::getline(std::cin, paragraphs[i]);
        }

        int x, y, max = 0;
        std::cin >> x >> y;

        for (int i = 8; i <= 28; i++)
        {
            if (fit(i, paragraphs, m, x, y))
            {
                max = i;
            }
            else
            {
                break;
            }
        }

        if (max != 0)
        {
            std::cout << max << std::endl;
        }
        else
        {
            std::cout << "No solution" << std::endl;
        }
    }

    return 0;
}