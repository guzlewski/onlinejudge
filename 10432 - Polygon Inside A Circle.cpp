#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    double r, n;

    while (std::cin >> r >> n)
    {
        double area = n * r * r / 2 * sin(2 * M_PI / n);
        std::cout << std::setprecision(3) << std::fixed << area << std::endl;
    }

    return 0;
}