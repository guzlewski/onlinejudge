#include <iostream>

void get_table(char *tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cin >> tab[i];
    }
}

void rotate(char *tab, int n)
{
    char temp[n * n];

    for (int i = 0; i < n * n; i++)
    {
        temp[i] = tab[i];
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            tab[x * n + n - 1 - y] = temp[y * n + x];
        }
    }
}

int fit(char *big, int bigSize, char *small, int smallSize)
{
    int count = 0;

    for (int startY = 0; startY <= bigSize - smallSize; startY++)
    {
        for (int startX = 0; startX <= bigSize - smallSize; startX++)
        {
            bool ok = true;

            for (int y = startY; y < startY + smallSize; y++)
            {
                for (int x = startX; x < startX + smallSize; x++)
                {
                    if (big[y * bigSize + x] != small[(y - startY) * smallSize + x - startX])
                    {
                        ok = false;
                        break;
                    }
                }
            }

            if (ok)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int N, n;

    while (std::cin >> N >> n && N && n)
    {
        char big[N * N], small[n * n];

        get_table(big, N * N);
        get_table(small, n * n);

        int result[4];
        for (int i = 0; i < 4; i++)
        {
            result[i] = fit(big, N, small, n);
            rotate(small, n);
        }

        std::cout << result[0] << " " << result[1] << " " << result[2] << " " << result[3] << std::endl;
    }

    return 0;
}