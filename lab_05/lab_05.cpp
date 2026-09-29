#include <iostream>
#include <iomanip>

using namespace std;

typedef int Boolean;

const Boolean TRUE = 1;
const Boolean FALSE = 0;

int main()
{
    long studentNumber;
    int rate1, rate2, rate3, rate4;
    float average;
    Boolean correct = TRUE;

    cout << "Введіть ідентифікаційний номер студента: ";
    cin >> studentNumber;

    cout << "Введіть 4 оцінки екзаменів студента: ";
    cin >> rate1 >> rate2 >> rate3 >> rate4;

    if (rate1 < 0 || rate2 < 0 || rate3 < 0 || rate4 < 0)
    {
        correct = FALSE;
    }

    cout << "Ідентифікаційний номер: " << studentNumber << endl;

    if (correct == FALSE)
    {
        cout << "Помилка: оцінка екзаменів не може бути від'ємною" << endl;
    }
    else
    {
        average = (rate1 + rate2 + rate3 + rate4) / 4.0;

        cout << fixed << setprecision(2);
        cout << "Середня оцінка: " << average << endl;

        if (average < 3)
        {
            cout << "Екзамен не складено" << endl;
        }
        else if (average < 4)
        {
            cout << "Екзамен складено задовільно" << endl;
        }
        else if (average < 5)
        {
            cout << "Екзамен складено добре" << endl;
        }
        else if (average == 5)
        {
            cout << "Екзамен складено відмінно" << endl;
        }
        else
        {
            cout << "Екзамен не складено" << endl;
        }
    }

    return 0;
}