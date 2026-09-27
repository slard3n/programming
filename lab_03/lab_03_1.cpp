#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, angle, b, c, P, S;

    cout << "Введіть катет a: ";
    cin >> a;

    cout << "Введіть гострий кут: ";
    cin >> angle;

    angle = angle * 3.141592653589793 / 180;

    b = a * tan(angle);
    c = a / cos(angle);

    P = a + b + c;
    S = a * b / 2;

    cout << "Периметр = " << P << endl;
    cout << "Площа = " << S << endl;

    return 0;
}