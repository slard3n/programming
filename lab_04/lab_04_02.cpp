#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    // задача 2
    const double x = 4.0;
    const double a = 3.0;
    const double b = 5.0;

    double y;

    if (x < a) {
        y = cos(a * x);
    }
    else if (x <= b && x >= a) {
        y = sqrt(pow(x, 4) + a);
    }
    else if (x > b) {
        y = abs(1) / abs(pow(b, 2) + pow(a, 2));
    }

    cout << fixed << setprecision(4);
    cout << "x = " << setw(8) << x << endl;
    cout << "a = " << setw(8) << a << endl;
    cout << "b = " << setw(8) << b << endl;
    cout << "y = " << setw(8) << y << endl;

    return 0;
}