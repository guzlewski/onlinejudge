#include <iostream>
#include <cstring>

bool input(int *tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> tab[i];
    }

    return tab[n - 1] != 0;
}

int main()
{
    int n, game = 0;
    while (std::cin >> n && n != 0)
    {
        int secret[n], guess[n];
        input(secret, n);

        std::cout << "Game " << ++game << ":" << std::endl;
        while (input(guess, n))
        {
            int strong = 0, weak = 0;
            int secret_copy[n];
            memcpy(secret_copy, secret, n * sizeof(int));

            for (int i = 0; i < n; i++)
            {
                if (guess[i] == secret[i])
                {
                    strong++;
                    guess[i] = 0;
                    secret_copy[i] = 0;
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (guess[i] == 0)
                {
                    continue;
                }

                for (int j = 0; j < n; j++)
                {
                    if (guess[i] == secret_copy[j])
                    {
                        weak++;
                        secret_copy[j] = 0;
                        break;
                    }
                }
            }

            std::cout << "    (" << strong << "," << weak << ")" << std::endl;
        }
    }

    return 0;
}