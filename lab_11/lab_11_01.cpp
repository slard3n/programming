#include <cctype>
#include <iostream>

using namespace std;

bool printState(char first, char second)
{
    switch (first)
    {
    case 'A':
        switch (second)
        {
        case 'L': cout << "Alabama"; return true;
        case 'K': cout << "Alaska"; return true;
        case 'Z': cout << "Arizona"; return true;
        case 'R': cout << "Arkansas"; return true;
        default: return false;
        }
    case 'C':
        switch (second)
        {
        case 'A': cout << "California"; return true;
        case 'O': cout << "Colorado"; return true;
        case 'T': cout << "Connecticut"; return true;
        default: return false;
        }
    case 'D':
        if (second == 'E') { cout << "Delaware"; return true; }
        return false;
    case 'F':
        if (second == 'L') { cout << "Florida"; return true; }
        return false;
    case 'G':
        if (second == 'A') { cout << "Georgia"; return true; }
        return false;
    case 'H':
        if (second == 'I') { cout << "Hawaii"; return true; }
        return false;
    case 'I':
        switch (second)
        {
        case 'D': cout << "Idaho"; return true;
        case 'L': cout << "Illinois"; return true;
        case 'N': cout << "Indiana"; return true;
        case 'A': cout << "Iowa"; return true;
        default: return false;
        }
    case 'K':
        switch (second)
        {
        case 'S': cout << "Kansas"; return true;
        case 'Y': cout << "Kentucky"; return true;
        default: return false;
        }
    case 'L':
        if (second == 'A') { cout << "Louisiana"; return true; }
        return false;
    case 'M':
        switch (second)
        {
        case 'E': cout << "Maine"; return true;
        case 'D': cout << "Maryland"; return true;
        case 'A': cout << "Massachusetts"; return true;
        case 'I': cout << "Michigan"; return true;
        case 'N': cout << "Minnesota"; return true;
        case 'S': cout << "Mississippi"; return true;
        case 'O': cout << "Missouri"; return true;
        case 'T': cout << "Montana"; return true;
        default: return false;
        }
    case 'N':
        switch (second)
        {
        case 'E': cout << "Nebraska"; return true;
        case 'V': cout << "Nevada"; return true;
        case 'H': cout << "New Hampshire"; return true;
        case 'J': cout << "New Jersey"; return true;
        case 'M': cout << "New Mexico"; return true;
        case 'Y': cout << "New York"; return true;
        case 'C': cout << "North Carolina"; return true;
        case 'D': cout << "North Dakota"; return true;
        default: return false;
        }
    case 'O':
        switch (second)
        {
        case 'H': cout << "Ohio"; return true;
        case 'K': cout << "Oklahoma"; return true;
        case 'R': cout << "Oregon"; return true;
        default: return false;
        }
    case 'P':
        if (second == 'A') { cout << "Pennsylvania"; return true; }
        return false;
    case 'R':
        if (second == 'I') { cout << "Rhode Island"; return true; }
        return false;
    case 'S':
        switch (second)
        {
        case 'C': cout << "South Carolina"; return true;
        case 'D': cout << "South Dakota"; return true;
        default: return false;
        }
    case 'T':
        if (second == 'N') { cout << "Tennessee"; return true; }
        if (second == 'X') { cout << "Texas"; return true; }
        return false;
    case 'U':
        if (second == 'T') { cout << "Utah"; return true; }
        return false;
    case 'V':
        switch (second)
        {
        case 'T': cout << "Vermont"; return true;
        case 'A': cout << "Virginia"; return true;
        default: return false;
        }
    case 'W':
        if (second == 'A') { cout << "Washington"; return true; }
        if (second == 'V') { cout << "West Virginia"; return true; }
        if (second == 'I') { cout << "Wisconsin"; return true; }
        if (second == 'Y') { cout << "Wyoming"; return true; }
        return false;
    default:
        return false;
    }
}

int main()
{
    char first, second;
    cout << "Введіть абревіатуру штату (для виходу введіть 0): ";

    while (cin >> first && first != '0')
    {
        cin >> second;
        first = static_cast<char>(toupper(static_cast<unsigned char>(first)));
        second = static_cast<char>(toupper(static_cast<unsigned char>(second)));

        if (!printState(first, second))
        {
            cout << "Помилка: невідома абревіатура." << endl;
            cout << "Введіть абревіатуру штату (для виходу введіть 0): ";
            continue;
        }

        cout << endl;

        cout << "Введіть абревіатуру штату (для виходу введіть 0): ";
    }

    return 0;
}
