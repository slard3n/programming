#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

char shiftLetter(char symbol, int shift)
{
    if (symbol >= 'A' && symbol <= 'Z')
        return static_cast<char>('A' + (symbol - 'A' + shift + 26) % 26);

    if (symbol >= 'a' && symbol <= 'z')
        return static_cast<char>('a' + (symbol - 'a' + shift + 26) % 26);

    return symbol;
}

string encode(const string& text, int shift)
{
    string result = text;

    for (char& symbol : result)
        symbol = shiftLetter(symbol, shift);

    return result;
}

int main()
{
    const int variant = 2;
    string text;

    do
    {
        cout << "Введіть текст (не більше 50 символів): ";
        getline(cin, text);

        if (text.length() > 50)
            cout << "Помилка: текст задовгий." << endl;
    } while (text.length() > 50);

    const string encoded = encode(text, variant);
    ofstream output("encoded.txt");

    if (!output.is_open())
    {
        cout << "Не вдалося відкрити encoded.txt для запису." << endl;
        return 1;
    }

    output << encoded;
    output.close();

    ifstream input("encoded.txt");
    if (!input.is_open())
    {
        cout << "Не вдалося відкрити encoded.txt для читання." << endl;
        return 1;
    }

    string encodedFromFile;
    getline(input, encodedFromFile);
    input.close();

    const string decoded = encode(encodedFromFile, -variant);

    cout << "Закодований текст: " << encodedFromFile << endl;
    cout << "Розкодований текст: " << decoded << endl;

    return 0;
}
