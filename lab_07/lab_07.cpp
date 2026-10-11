#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text = "abc!=\ndef!=\nabc!\ndef========\nabc!!!!!!!!=!=abc !=";
    int count = 0;
    int i = 0;

    while (i < text.length())
    {
        if (text[i] == '!' || text[i] == '=')
        {
            count++;
        }
        i++;
    }

    cout << count << endl;

    return 0;
}
