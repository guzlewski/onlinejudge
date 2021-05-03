#include <iostream>
#include <iomanip>

bool is_digit(char &x)
{
    return x >= '0' && x <= '9';
}

double mass(char &element, std::string &count_str)
{
    int count = 1;

    if (count_str.length() != 0)
    {
        count = std::stoi(count_str);
    }

    switch (element)
    {
    case 'C':
        return 12.01 * count;
    case 'H':
        return 1.008 * count;
    case 'O':
        return 16.00 * count;
    case 'N':
        return 14.01 * count;
    default:
        return 0;
    }
}

double mass(std::string &formula)
{
    double sum = 0;
    char element;
    std::string count;

    for (unsigned int i = 0; i < formula.length(); i++)
    {
        element = formula[i++];
        count = "";

        while (i != formula.length() && is_digit(formula[i]))
        {
            count += formula[i];
            i++;
        }

        sum += mass(element, count);
        i--;
    }

    return sum;
}

int main()
{
    int tests;
    std::cin >> tests;

    while (tests--)
    {
        std::string formula;
        std::cin >> formula;

        std::cout << std::setprecision(3) << std::fixed << mass(formula) << std::endl;
    }
}