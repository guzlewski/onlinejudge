#include <iostream>
#include <map>

bool input(std::map<int, int> &pearls)
{
    pearls.clear();
    int pearl;

    while (std::cin >> pearl && pearl != 0)
    {
        pearls[pearl]++;
    }

    return pearls.size() != 0;
}

bool can_form(std::map<int, int> &pearls)
{
    auto largest = --pearls.end();

    if (largest->second != 1)
    {
        return false;
    }

    for (auto &keyval : pearls)
    {
        if (keyval == *largest)
        {
            return true;
        }

        if (keyval.second != 2)
        {
            return false;
        }
    }

    return true;
}

void display(std::map<int, int> &pearls)
{
    for (auto &keyval : pearls)
    {
        std::cout << keyval.first;

        if (pearls.size() != 1)
        {
            std::cout << " ";
        }
    }

    for (auto it = ++pearls.rbegin(); it != pearls.rend(); it++)
    {
        std::cout << it->first;

        if (it != --pearls.rend())
        {
            std::cout << " ";
        }
    }

    std::cout << std::endl;
}

int main()
{
    std::map<int, int> pearls;

    while (input(pearls))
    {
        if (can_form(pearls))
        {
            display(pearls);
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}