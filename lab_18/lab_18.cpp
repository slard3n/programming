#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string surname;
    string name;
    string group;
    double average;
};

void printStudent(const Student& student)
{
    cout << left << setw(16) << student.surname
         << setw(14) << student.name
         << setw(10) << student.group
         << fixed << setprecision(2) << student.average << endl;
}

int main()
{
    const int studentCount = 7;
    const double searchAverage = 4.5;

    Student students[studentCount] =
    {
        {"Шевченко", "Олена", "КН-21", 4.80},
        {"Бондаренко", "Андрій", "КН-21", 4.10},
        {"Коваленко", "Марія", "КН-22", 4.70},
        {"Мельник", "Ігор", "КН-22", 3.90},
        {"Ткаченко", "Софія", "КН-21", 4.50},
        {"Романюк", "Дмитро", "КН-23", 3.70},
        {"Кравченко", "Анна", "КН-23", 4.90}
    };

    cout << "Список студентів" << endl;
    cout << left << setw(16) << "Прізвище"
         << setw(14) << "Ім'я"
         << setw(10) << "Група"
         << "Середній бал" << endl;
    cout << string(52, '-') << endl;

    for (int i = 0; i < studentCount; i++)
        printStudent(students[i]);

    cout << "\nСтуденти із середнім балом не нижче "
         << searchAverage << ":" << endl;

    bool found = false;
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].average >= searchAverage)
        {
            cout << students[i].surname << " " << students[i].name
                 << " (" << students[i].group << ")" << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Таких студентів немає." << endl;

    return 0;
}
