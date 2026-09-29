#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//задача 1, спільна для всіх

int main() {
    const double centerX = 3.0;
    const double centerY = 2.0;
    const double radius = 5.0;

    double x, y;

    cout << fixed << setprecision(2);

    cout << "Центр кола: (" << centerX << ", " << centerY << ")" << endl;
    cout << "Радіус: " << radius << endl;

    while (true) {
        cout << "\n Введіть точку координати x: ";
        cin >> x ;
        cout << " Введіть точку координати y: ";
        cin >> y;

        double distance = sqrt(pow(x - centerX, 2) + pow(y - centerY, 2));

        if (x == centerX && y == centerY) {
            cout << "Точка в центрі кола." << endl;
            break;
        }
        else if (distance < radius) {
            cout << "Точка всередині кола." << endl;
            break;
        }
        else if (distance > radius) {
            cout << "Точка поза колом." << endl;
            break;
        }
        else {
            cout << "Точка лежить на колі." << endl;
            cout << "Введіть іншу точку." << endl;
        }
    }

    return 0;
}