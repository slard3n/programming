#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

int main()
{
    int variant;
    double start, step, coefficient;
    int rows;
    string firstMeasure, secondMeasure;

    cout << "Лабораторна робота №6\n";
    cout << "Таблиця відповідностей між мірами\n\n";
    cout << "1. Унція - карати\n";
    cout << "2. Драхма - унції\n";
    cout << "3. Карати - грани\n";
    cout << "4. Грани - драхми\n";
    cout << "5. Пайни - пеки\n";
    cout << "6. Галони (британські) - галони (США)\n";
    cout << "7. Галони (США) - саки\n";
    cout << "8. Карби - пайпи\n";
    cout << "9. Квартети - чарки\n";
    cout << "10. Страйки - чарки\n";
    cout << "11. Челдрони - пеки\n";
    cout << "12. Саки - страйки\n\n";

    cout << "Оберіть варіант (1-12): ";
    while (!(cin >> variant) || variant < 1 || variant > 12)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Введіть число від 1 до 12: ";
    }

    if (variant == 1)
    {
        firstMeasure = "унцій";
        secondMeasure = "каратів";
        coefficient = 142;
    }
    else if (variant == 2)
    {
        firstMeasure = "драхм";
        secondMeasure = "унцій";
        coefficient = 0.06249;
    }
    else if (variant == 3)
    {
        firstMeasure = "каратів";
        secondMeasure = "гранів";
        coefficient = 2.9412;
    }
    else if (variant == 4)
    {
        firstMeasure = "гранів";
        secondMeasure = "драхм";
        coefficient = 0.03878;
    }
    else if (variant == 5)
    {
        firstMeasure = "пайнів";
        secondMeasure = "пеків";
        coefficient = 54.18;
    }
    else if (variant == 6)
    {
        firstMeasure = "галонів (британських)";
        secondMeasure = "літрів";
        coefficient = 4.546;
    }
    else if (variant == 7)
    {
        firstMeasure = "галонів (США)";
        secondMeasure = "літрів";
        coefficient = 3.785;
    }
    else if (variant == 8)
    {
        firstMeasure = "карбів";
        secondMeasure = "пайпів";
        coefficient = 0.0012;
    }
    else if (variant == 9)
    {
        firstMeasure = "квартетів";
        secondMeasure = "чарок";
        coefficient = 5123.24;
    }
    else if (variant == 10)
    {
        firstMeasure = "страйків";
        secondMeasure = "чарок";
        coefficient = 1280.46 / 72.73;
    }
    else if (variant == 11)
    {
        firstMeasure = "челдронів";
        secondMeasure = "пеків";
        coefficient = 1.309;
    }
    else
    {
        firstMeasure = "саків";
        secondMeasure = "страйків";
        coefficient = 1.499 / 109;
    }

    cout << "Початкове значення: ";
    while (!(cin >> start))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Введіть число: ";
    }

    cout << "Крок зміни: ";
    while (!(cin >> step) || step == 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Введіть ненульове число: ";
    }

    cout << "Кількість рядків (10-15): ";
    while (!(cin >> rows) || rows < 10 || rows > 15)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Введіть ціле число від 10 до 15: ";
    }

    cout << "\nПереведення: " << firstMeasure << " -> " << secondMeasure << endl;
    cout << "+-----------------------+-----------------------+" << endl;
    cout << "| Значення              | Результат             |" << endl;
    cout << "+-----------------------+-----------------------+" << endl;

    int i = 0;
    double value = start;
    while (i < rows)
    {
        cout << fixed << setprecision(4);
        cout << "|" << left << setw(23) << value
             << "|" << setw(23) << value * coefficient << "|" << endl;
        value += step;
        i++;
    }

    cout << "+-----------------------+-----------------------+" << endl;

    return 0;
}
