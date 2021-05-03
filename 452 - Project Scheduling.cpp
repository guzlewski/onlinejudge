#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

std::unordered_map<char, int> dependenciesCounter;

class task
{
public:
    char name;
    int cost;
    std::vector<char> dependencies;

    task()
    {
        name = 0;
        cost = 0;
    }

    task(char _name, int _cost, std::string _dependencies)
    {
        name = _name;
        cost = _cost;

        for (unsigned int i = 0; i < _dependencies.length(); i++)
        {
            dependencies.push_back(_dependencies[i]);
            dependenciesCounter[_dependencies[i]]++;
        }
    }
};

int dfs(int cost, char current, std::unordered_map<char, task> &tasks)
{
    if (tasks[current].dependencies.size() == 0)
    {
        return cost + tasks[current].cost;
    }

    int max = 0;

    for (unsigned int i = 0; i < tasks[current].dependencies.size(); i++)
    {
        int temp = dfs(cost + tasks[current].cost, tasks[current].dependencies[i], tasks);
        max = std::max(max, temp);
    }

    return max;
}

int main()
{
    int tests;
    std::cin >> tests;
    tests++;

    std::string line;
    std::cin.ignore();

    while (tests--)
    {
        bool read = false;
        std::unordered_map<char, task> tasks;
        dependenciesCounter.clear();

        while (std::getline(std::cin, line))
        {
            if (line.length() == 0)
            {
                break;
            }

            read = true;

            char name = 0;
            int cost = 0;
            std::string dependencies = "";
            std::stringstream ss(line);

            ss >> name >> cost >> dependencies;
            tasks[name] = (task(name, cost, dependencies));
        }

        if (read)
        {
            int max = 0;

            for (char i = 'A'; i <= 'A' + (char)tasks.size(); i++)
            {
                if (dependenciesCounter[i] != 0)
                {
                    continue;
                }

                int temp = dfs(0, i, tasks);
                max = std::max(max, temp);
            }

            std::cout << max << std::endl;

            if (tests != 0)
            {
                std::cout << std::endl;
            }
        }
    }

    return 0;
}