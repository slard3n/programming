#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int grade1;
    int grade2;
    int grade3;

    double weight1;
    double weight2;
    double weight3;

    cout << "Введіть першу оцінку та її ваговий коефіцієнт: " << endl;
    cin >> grade1 >> weight1;

    cout << "Введіть другу оцінку та її ваговий коефіцієнт: " << endl;
    cin >> grade2 >> weight2;

    cout << "Введіть третю оцінку та її ваговий коефіцієнт: " << endl;
    cin >> grade3 >> weight3;

    double average = grade1 * weight1 + grade2 * weight2 + grade3 * weight3;

    cout << fixed << setprecision(2);

    cout << endl;
    cout << "Перша оцінка: " << grade1 << endl;
    cout << "Ваговий коефіцієнт: " << weight1 << endl;

    cout << "Друга оцінка: " << grade2 << endl;
    cout << "Ваговий коефіцієнт: " << weight2 << endl;

    cout << "Третя оцінка: " << grade3 << endl;
    cout << "Ваговий коефіцієнт: " << weight3 << endl;

    cout << "Середньозважене значення оцінки: " << average << endl;

    return 0;
}