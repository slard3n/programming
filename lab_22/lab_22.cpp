#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SortedStrings
{
public:
    void AddString(const string& text)
    {
        strings.push_back(text);
    }

    vector<string> GetSortedStrings() const
    {
        vector<string> result = strings;
        sort(result.begin(), result.end());
        return result;
    }

private:
    vector<string> strings;
};

void PrintSortedStrings(const SortedStrings& strings)
{
    for (const string& text : strings.GetSortedStrings())
        cout << text << ' ';
    cout << endl;
}

int main()
{
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}
