#include <iostream>

using namespace std;

unsigned long long PrintFactorial(int number)
{
    unsigned long long result = 1;
    int i = 2;

    while (i <= number)
    {
        result *= i;
        i++;
    }

    return result;
}

int main()
{
    int number;

    cout << "Введіть невід'ємне число (від'ємне завершує роботу): ";
    while (cin >> number && number >= 0)
    {
        cout << number << "! = " << PrintFactorial(number) << endl;
        cout << "Введіть наступне число: ";
    }

    cout << "Роботу завершено." << endl;

    return 0;
}
