#include <iostream>
#include <vector>
#include <string>

std::string range(int begin, int end)
{
    std::string beginStr = std::to_string(begin);
    std::string endStr = std::to_string(end);
    std::string result = "";
    bool changed = false;

    for (unsigned int i = 0; i < beginStr.length(); i++)
    {
        if (beginStr[i] != endStr[i])
        {
            changed = true;
        }

        if (changed)
        {
            result += endStr[i];
        }
    }

    return result;
}

int main()
{
    int n, caseNr = 0;
    while (std::cin >> n && n != 0)
    {
        std::vector<long long> numbers;

        for (int i = 0; i < n; i++)
        {
            std::string number;
            std::cin >> number;
            numbers.push_back(std::stoll(number));
        }

        long long start = 0;
        numbers.push_back(0);

        std::cout << "Case " << ++caseNr << ":" << std::endl;

        for (unsigned int i = 0; i < numbers.size() - 1; i++)
        {
            if (numbers[i] + 1 == numbers[i + 1])
            {
                if (start == 0)
                {
                    start = numbers[i];
                }
            }
            else
            {
                if (start != 0)
                {
                    std::cout << 0 << start << "-" << range(start, numbers[i]) << std::endl;
                    start = 0;
                }
                else
                {
                    std::cout << 0 << numbers[i] << std::endl;
                }
            }
        }

        std::cout << std::endl;
    }
}