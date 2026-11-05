#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    const int variant = 2;
    const int towns = 6;
    const int candidates = 5;
    int votes[towns][candidates];
    int selectedTowns[towns];
    int selectedCount = 0;

    srand(static_cast<unsigned>(time(nullptr)));

    for (int town = 0; town < towns; town++)
    {
        int townTotal = 0;
        for (int candidate = 0; candidate < candidates; candidate++)
        {
            votes[town][candidate] = rand() % 500 + 50 * variant;
            townTotal += votes[town][candidate];
        }

        if (townTotal > 150)
            selectedTowns[selectedCount++] = town + 1;
    }

    cout << "Таблиця результатів голосування" << endl;
    cout << "Населений пункт";
    for (int candidate = 1; candidate <= candidates; candidate++)
        cout << setw(12) << ("Кандидат " + to_string(candidate));
    cout << endl;

    for (int town = 0; town < towns; town++)
    {
        cout << setw(16) << town + 1;
        for (int candidate = 0; candidate < candidates; candidate++)
            cout << setw(12) << votes[town][candidate];
        cout << endl;
    }

    cout << "\nНомери населених пунктів із кількістю голосів понад 150: ";
    for (int i = 0; i < selectedCount; i++)
        cout << selectedTowns[i] << (i + 1 == selectedCount ? '\n' : ' ');

    return 0;
}
