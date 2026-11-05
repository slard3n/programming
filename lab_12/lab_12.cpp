#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

double f7(double x)
{
    return fabs(sin(2.0 * x - 1.5) + 3.0 * sin(4.0 * x)) + 2.38;
}

double f8(double x)
{
    return cos(x) * cos(x) * sin(2.0 * x - 1.0) + 4.29;
}

int phoneDigit(char letter)
{
    switch (letter)
    {
    case 'A': case 'B': case 'C': return 2;
    case 'D': case 'E': case 'F': return 3;
    case 'G': case 'H': case 'I': return 4;
    case 'J': case 'K': case 'L': return 5;
    case 'M': case 'N': case 'O': return 6;
    case 'P': case 'R': case 'S': return 7;
    case 'T': case 'U': case 'V': return 8;
    case 'W': case 'X': case 'Y': return 9;
    default: return 0;
    }
}

void convertLetters()
{
    char letter;

    do
    {
        cout << "Введіть літеру (Q або Z — вихід): ";
        cin >> letter;
        letter = static_cast<char>(toupper(static_cast<unsigned char>(letter)));

        if (letter == 'Q' || letter == 'Z')
        {
            cout << "Вихід." << endl;
            break;
        }

        if (isdigit(static_cast<unsigned char>(letter)) || phoneDigit(letter) == 0)
        {
            cout << "Введений неправильний символ. Введіть Q або Z для виходу." << endl;
        }
        else
        {
            cout << "Буква " << letter << " відповідає цифрі "
                 << phoneDigit(letter) << " на телефоні." << endl;
        }
    } while (letter != 'Q' && letter != 'Z');
}

int main()
{
    const int variant = 2;
    double a = 0.0;
    double b = 1.0;
    int k = variant;

    convertLetters();

    do
    {
        a += f7(k);
        k++;
    } while (k <= variant + 5);

    k = variant;
    do
    {
        b *= f8(k);
        k++;
    } while (k <= variant + 8);

    double z = a * b;

    cout << fixed << setprecision(6);
    cout << "\nВаріант: " << variant << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "z = " << z << endl;

    return 0;
}
