#include <iostream>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <cstring>

bool is_palindrom(std::string &s, int start, unsigned int length)
{
    if (start < 0)
    {
        return false;
    }

    if (length > s.length())
    {
        return false;
    }

    for (int i = start, j = start + length - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::string input;
    while (std::cin >> input)
    {
        std::unordered_set<std::string> palindromes;
        std::queue<std::pair<int, unsigned int>> queue;

        for (unsigned int i = 0; i < input.length(); i++)
        {
            queue.push(std::make_pair(i, 1));
        }

        while (!queue.empty())
        {
            auto pair = queue.front();
            queue.pop();

            std::string palindrom(pair.second, '\0');
            memcpy(&palindrom[0], &input[pair.first], pair.second);
            palindromes.insert(palindrom);

            if (is_palindrom(input, pair.first - 1, pair.second + 1))
            {
                queue.push(std::make_pair(pair.first - 1, pair.second + 1));
            }

            if (is_palindrom(input, pair.first, pair.second + 1))
            {
                queue.push(std::make_pair(pair.first, pair.second + 1));
            }

            if (is_palindrom(input, pair.first - 1, pair.second + 2))
            {
                queue.push(std::make_pair(pair.first - 1, pair.second + 2));
            }
        }

        std::cout << "The string '" << input << "' contains " << palindromes.size() << " palindromes." << std::endl;
    }

    return 0;
}