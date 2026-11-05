#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class ReversibleString
{
public:
    // Конструктор за замовчуванням створює порожній рядок.
    ReversibleString() : value("")
    {
    }

    // Параметризований конструктор одразу зберігає переданий рядок.
    ReversibleString(const string& text) : value(text)
    {
    }

    // Деструктор викликається автоматично під час знищення об'єкта.
    ~ReversibleString()
    {
    }

    void Reverse()
    {
        reverse(value.begin(), value.end());
    }

    string ToString() const
    {
        return value;
    }

private:
    string value;
};

int main()
{
    ReversibleString text("live");
    text.Reverse();
    cout << text.ToString() << endl;

    text.Reverse();
    const ReversibleString& textReference = text;
    string copy = textReference.ToString();
    cout << copy << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}
