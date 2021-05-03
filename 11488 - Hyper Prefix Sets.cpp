#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main()
{
    int tests;
    std::cin >> tests;

    while (tests--)
    {
        int n;
        std::cin >> n;
        std::unordered_map<std::string, int> prefixes;

        for (int i = 0; i < n; i++)
        {
            std::string temp;
            std::cin >> temp;

            for (unsigned int j = 1; j <= temp.length(); j++)
            {
                prefixes[temp.substr(0, j)]++;
            }
        }

        int max = 0;

        for (auto &pair : prefixes)
        {
            int value = pair.second * pair.first.length();
            max = std::max(max, value);
        }

        std::cout << max << std::endl;
    }
}