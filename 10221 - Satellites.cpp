#include <iostream>
#include <iomanip>
#include <cmath>

bool input(int &s, double &a)
{
    std::string mode;

    if (!(std::cin >> s >> a >> mode))
    {
        return false;
    }

    if (mode == "min")
    {
        a /= 60;
    }

    return true;
}

void calculate(int s, double a, double &arc, double &chord)
{
    s += 6440;

    if (a > 180)
    {
        a = 360 - a;
    }

    arc = (a / 360.0) * 2 * M_PI * s;
    chord = std::sqrt(2 * (s * s) - 2 * s * s * std::cos((a * M_PI) / 180.0));
}

int main()
{
    int s;
    double a;

    while (input(s, a))
    {
        double arc, chord;
        calculate(s, a, arc, chord);
        std::cout << std::setprecision(6) << std::fixed << arc << " " << chord << std::endl;
    }
}