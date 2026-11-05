#include <iostream>

using namespace std;

double PrintTemp(double celsius)
{
    return 1.8 * celsius + 32.0;
}

int main()
{
    double celsius;

    cout << "Будь-ласка, введіть температуру у градусах за Цельсієм: ";
    cin >> celsius;

    cout << celsius << " градусів за Цельсієм дорівнює "
         << PrintTemp(celsius) << " градусів за Фаренгейтом" << endl;

    return 0;
}
