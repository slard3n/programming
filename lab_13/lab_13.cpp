#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

// Функція f10(x) з таблиці до лабораторної роботи №15.
double f10(double x)
{
    return sin(x) - pow(cos(x), 3) * sin(x * x - 4.2) + 4.27;
}

int main()
{
    const int variant = 2;
    const double h = 0.1 * variant;
    const int points = static_cast<int>(variant / h);
    double sum = 0.0;
    double product = 1.0;
    int selected = 0;

    cout << fixed << setprecision(6);
    cout << "Табуляція y = f10(x), варіант " << variant << endl;
    cout << "--------------------------------" << endl;
    cout << "     x             y" << endl;
    cout << "--------------------------------" << endl;

    for (int step = 0; step <= points; step++)
    {
        double x = step * h;
        double y = f10(x);

        cout << setw(10) << x << setw(16) << y << endl;

        if (y < -3.2 || y > 0.0)
        {
            sum += y;
            product *= y;
            selected++;
        }
    }

    cout << "--------------------------------" << endl;

    if (selected == 0)
    {
        cout << "Шуканих значень немає." << endl;
    }
    else
    {
        cout << "Кількість вибраних значень: " << selected << endl;
        cout << "Сума: " << sum << endl;
        cout << "Добуток: " << product << endl;
    }

    return 0;
}
