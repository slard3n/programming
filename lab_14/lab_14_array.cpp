#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

double f11(double x)
{
    return fabs(sin(12.0 * x) * cos(fabs(2.0 * x)) / 3.0) + 4.21;
}

int main()
{
    const int firstYear = 2000;
    const int lastYear = 2010;
    const int size = lastYear - firstYear + 1;
    double profit[size];
    double lossSum = 0.0;
    double largestLoss = 0.0;
    int largestLossYear = 0;
    bool hasLosses = false;

    for (int i = 0; i < size; i++)
    {
        int year = firstYear + i;
        profit[i] = 100.0 * f11(year);

        if (profit[i] < 0.0)
        {
            lossSum += profit[i];
            if (!hasLosses || profit[i] < largestLoss)
            {
                largestLoss = profit[i];
                largestLossYear = year;
                hasLosses = true;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << "Рік          Прибуток" << endl;
    for (int i = 0; i < size; i++)
        cout << firstYear + i << "         " << profit[i] << endl;

    cout << "\nВаріант 2 (звичайний масив)" << endl;
    if (hasLosses)
    {
        cout << "Сума збитків: " << lossSum << endl;
        cout << "Найбільший збиток був у " << largestLossYear
             << " році: " << largestLoss << endl;
    }
    else
    {
        cout << "Збитків не було." << endl;
    }

    return 0;
}
