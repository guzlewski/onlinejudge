#include <iostream>
#include <vector>
#include <map>

int resolve(std::vector<std::string *> &names, int index)
{
    if (names.size() == 1)
    {
        if (index == 0)
        {
            return 1;
        }

        return index;
    }

    std::map<char, std::vector<std::string *>> letters;

    for (unsigned int i = 0; i < names.size(); i++)
    {
        letters[names[i]->at(index)].push_back(names.at(i));
    }

    int sum = 0;

    for (auto &pair : letters)
    {
        sum += resolve(pair.second, index + 1);
    }

    return sum;
}

int main()
{
    int tests;
    std::cin >> tests;

    while (tests--)
    {
        int n;
        std::cin >> n;

        std::string names[n];
        std::vector<std::string *> names_pointers;

        for (int i = 0; i < n; i++)
        {
            std::string name;
            std::cin >> names[i];
            names_pointers.push_back(names + i);
        }

        std::cout << resolve(names_pointers, 0) << std::endl;
    }

    return 0;
}