#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double i = 2;

    double xA = 0, yA = 0;
    double xB = i, yB = i - 1;
    double xC = -i, yC = i + 1;

    double a, b, c, p;
    double mb, Wb;

    a = sqrt(pow(xC - xB, 2) + pow(yC - yB, 2));
    b = sqrt(pow(xC - xA, 2) + pow(yC - yA, 2));
    c = sqrt(pow(xB - xA, 2) + pow(yB - yA, 2));

    p = (a + b + c) / 2;

    mb = 0.5 * sqrt(2 * a * a + 2 * c * c - b * b);

    Wb = (2.0 / (a + c)) * sqrt(a * c * p * (p - b));

    cout << "Медіана = " << mb << endl;
    cout << "Бісектриса = " << Wb << endl;

    return 0;
}