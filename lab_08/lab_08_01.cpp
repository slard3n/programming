#include <iostream>
#include <limits>

using namespace std;

void calculate(double firstNumber, char operation, double secondNumber)
{
    if (operation == '+')
    {
        cout << "Результат дорівнює " << firstNumber + secondNumber << endl;
    }
    else if (operation == '-')
    {
        cout << "Результат дорівнює " << firstNumber - secondNumber << endl;
    }
    else if (operation == '*')
    {
        cout << "Результат дорівнює " << firstNumber * secondNumber << endl;
    }
    else if (operation == '/')
    {
        if (secondNumber == 0)
        {
            cout << "На нуль ділити не можна." << endl;
        }
        else
        {
            cout << "Результат дорівнює " << firstNumber / secondNumber << endl;
        }
    }
    else
    {
        cout << "Невідома операція." << endl;
    }
}

int main()
{
    char answer = 'y';

    while (answer == 'y' || answer == 'Y')
    {
        double firstNumber, secondNumber;
        char operation;

        cout << "Введіть перший операнд, операцію і другий операнд: ";
        while (!(cin >> firstNumber >> operation >> secondNumber))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Введіть дані у форматі: 10 / 3: ";
        }

        calculate(firstNumber, operation, secondNumber);

        cout << "Виконати ще одну операцію (y/n)? ";
        cin >> answer;
        cout << endl;
    }

    return 0;
}
