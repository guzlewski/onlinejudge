#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    int tests;
    std::cin >> tests;

    while (tests--)
    {
        int n;
        std::cin >> n;

        std::vector<std::string> numbers(n);
        std::unordered_map<std::string, int> prefixes;

        for (int i = 0; i < n; i++)
        {
            std::string number;
            std::cin >> number;

            numbers[i] = number;

            for (unsigned int i = 1; i <= number.length() - 1; i++)
            {
                prefixes[number.substr(0, i)]++;
            }
        }
        bool consistent = true;

        for (int i = 0; i < n; i++)
        {
            if (prefixes[numbers[i]] != 0)
            {
                consistent = false;
                break;
            }
        }

        if (consistent)
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }
}