#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    ifstream input("input.dat");
    ofstream output("negative.rez");

    if (!input.is_open() || !output.is_open())
    {
        cout << "Не вдалося відкрити файл." << endl;
        return 1;
    }

    const int amount = 50;
    int negativeCount = 0;
    int position = 0;
    double value;

    output << fixed << setprecision(2);
    output << "Позиція       Значення" << endl;

    while (position < amount && input >> value)
    {
        position++;

        if (value < 0)
        {
            negativeCount++;
            output << setw(7) << position << setw(15) << value << endl;
        }
    }

    cout << "Кількість від'ємних чисел: " << negativeCount << endl;

    if (position < amount)
        cout << "Попередження: у файлі менше ніж 50 чисел." << endl;

    input.close();
    output.close();

    return 0;
}
