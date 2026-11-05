#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

double f12(double x)
{
    return pow(cos(x), 3) / 2.1
        + pow(cos(x), 2) / 1.1
        - 8.3 * sin(3.0 * x + 1.0);
}

int main()
{
    const int variant = 2;
    const int size = 7;
    vector<double> values(size);

    for (int i = 0; i < size; i++)
        values[i] = f12(i + 1);

    int largest = 0;
    int secondLargest = 1;
    if (values[secondLargest] > values[largest])
        swap(largest, secondLargest);

    for (int i = 2; i < size; i++)
    {
        if (values[i] > values[largest])
        {
            secondLargest = largest;
            largest = i;
        }
        else if (values[i] > values[secondLargest])
        {
            secondLargest = i;
        }
    }

    cout << fixed << setprecision(6);
    cout << "Масив y = f12(k), варіант " << variant << endl;
    for (int i = 0; i < size; i++)
        cout << "y[" << i + 1 << "] = " << values[i] << endl;

    cout << "Номери двох найбільших елементів: "
         << largest + 1 << " і " << secondLargest + 1 << endl;
    cout << "Їх сума: " << values[largest] + values[secondLargest] << endl;

    return 0;
}
