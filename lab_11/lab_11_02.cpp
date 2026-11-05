#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

double F4(double x)
{
    return fabs(sin(x) / 3.12 + cos(x) * cos(x)) - 8.3 * sin(3 * x);
}

double F5(double x)
{
    return cos(fabs(2 * x)) / 1.12 - cos(3 * x - 2) + 6.15;
}

double F6(double x)
{
    return sin(x) * cos(x) * cos(x) * sin(x + 1.4) / 0.85 + 7.14;
}

double workValue(char type)
{
    const int variant = 2;

    switch (type)
    {
    case 'A': return 100.0 * fabs(F4(variant) + 50.0);
    case 'B': return 150.0 * fabs(F5(variant) + 100.0);
    case 'C': return 200.0 * fabs(F6(variant) + 135.0);
    default: return 0.0;
    }
}

void printPayment(char type)
{
    double payment = workValue(type);
    double taxRate = type == 'A' ? 0.10 : type == 'B' ? 0.15 : 0.20;
    double tax = payment * taxRate;

    cout << fixed << setprecision(2);
    cout << "Нараховано: " << payment << endl;
    cout << "Податок: " << tax << endl;
    cout << "До видачі: " << payment - tax << endl;
}

int main()
{
    char type, method;

    cout << "Варіант 2. Введіть тип роботи (A, B, C): ";
    cin >> type;
    type = static_cast<char>(toupper(static_cast<unsigned char>(type)));
    cout << "Оберіть спосіб (S - switch, G - goto): ";
    cin >> method;
    method = static_cast<char>(toupper(static_cast<unsigned char>(method)));

    if (method == 'S')
    {
        switch (type)
        {
        case 'A':
        case 'B':
        case 'C':
            printPayment(type);
            break;
        default:
            cout << "Неправильний тип роботи." << endl;
        }
    }
    else if (method == 'G')
    {
choose_type:
        switch (type)
        {
        case 'A':
        case 'B':
        case 'C':
            printPayment(type);
            break;
        default:
            cout << "Неправильний тип. Введіть A, B або C: ";
            cin >> type;
            type = static_cast<char>(toupper(static_cast<unsigned char>(type)));
            goto choose_type;
        }
    }
    else
    {
        cout << "Неправильний спосіб розв'язання." << endl;
    }

    return 0;
}
