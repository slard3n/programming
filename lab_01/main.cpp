#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "ЗАВДАННЯ 1" << endl;
    float width = 30.0;
    float length = 40.0;
    float floors = 2.5;
    float nonResidentialArea = 825.0;
    float price = 150000.0;

    float totalArea = width * length * floors;
    float residentialArea = totalArea - nonResidentialArea;
    float pricePerSquareMeter = price / residentialArea;

    cout << fixed << setprecision(2);

    cout << "Загальна площа будинку: " << totalArea << " м2" << endl;
    cout << "Житлова площа: " << residentialArea << " м2" << endl;
    cout << "Вартість 1 м2 житлової площі: "
         << pricePerSquareMeter << " грн" << endl;

    cout << endl;
    cout << "ЗАВДАННЯ 2" << endl;

    float first = 1.5;
    float second = 2.3;
    float third = 5.9;
    float fourth = 4.0;
    float scale = 0.25;

    float distance1 = first * scale;
    float distance2 = second * scale;
    float distance3 = third * scale;
    float distance4 = fourth * scale;

    float totalDistance = distance1 + distance2 + distance3 + distance4;

    float roundedDistance =
        float(int(totalDistance * 10.0 + 0.5)) / 10.0;

    cout << fixed << setprecision(3);

    cout << "Відстань на карті:" << endl;
    cout << "1: " << first << " см" << endl;
    cout << "2: " << second << " см" << endl;
    cout << "3: " << third << " см" << endl;
    cout << "4: " << fourth << " см" << endl;

    cout << endl;

    cout << "Масштаб: 1 см = " << scale << " км" << endl;

    cout << endl;

    cout << "Відстані між об'єктами:" << endl;
    cout << "1: " << distance1 << " км" << endl;
    cout << "2: " << distance2 << " км" << endl;
    cout << "3: " << distance3 << " км" << endl;
    cout << "4: " << distance4 << " км" << endl;

    cout << endl;

    cout << fixed << setprecision(1);
    cout << "Повний шлях: " << roundedDistance << " км" << endl;

    return 0;
}