#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

double f13(double x)
{
    return sin(x) * sin(x) * cos(x) * cos(x) * cos(x) - sin(x) + 5.2;
}

double f14(double x)
{
    return 2.0 * sin(x) * sin(2.0 * x - 1.5) * cos(2.0 * x + 1.5) - 6.0;
}

int main()
{
    const int variant = 2;
    const int size = 4;
    vector<vector<double>> matrix(size, vector<double>(size));
    int count = 0;

    for (int n = 1; n <= size; n++)
    {
        for (int k = 1; k <= size; k++)
        {
            matrix[n - 1][k - 1] = n * f13(k) + sin(k) * f14(n);
            if (matrix[n - 1][k - 1] > 1.0 && matrix[n - 1][k - 1] < 6.0)
                count++;
        }
    }

    cout << fixed << setprecision(5);
    cout << "Матриця a(k,n), варіант " << variant << endl;
    for (int n = 0; n < size; n++)
    {
        for (int k = 0; k < size; k++)
            cout << setw(12) << matrix[n][k];
        cout << endl;
    }

    cout << "Кількість елементів, для яких 1 < a(k,n) < 6: "
         << count << endl;
    return 0;
}
