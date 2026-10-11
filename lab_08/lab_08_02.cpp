#include <iostream>

using namespace std;

void printSymbol(char symbol, int count)
{
    int i = 0;

    while (i < count)
    {
        cout << symbol;
        i++;
    }

    cout << endl;
}

int main()
{
    char symbol;
    int count;

    cout << "Введіть символ: ";
    cin >> symbol;

    cout << "Введіть кількість повторень: ";
    while (!(cin >> count) || count <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введіть ціле число більше нуля: ";
    }

    printSymbol(symbol, count);

    return 0;
}
