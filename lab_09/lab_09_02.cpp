#include <iostream>

using namespace std;

double PrintGarm(double x, double y)
{
    return 2.0 * x * y / (x + y);
}

int main()
{
    double x, y;

    cout << "Вводьте пари чисел (нуль завершує роботу)." << endl;
    cout << "Введіть першу пару: ";

    while (cin >> x >> y && x != 0 && y != 0)
    {
        if (x + y == 0)
        {
            cout << "Для цієї пари середнє гармонійне не визначене." << endl;
        }
        else
        {
            cout << "Середнє гармонійне дорівнює " << PrintGarm(x, y) << endl;
        }
        cout << "Введіть наступну пару: ";
    }

    cout << "Роботу завершено." << endl;

    return 0;
}
