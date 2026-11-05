#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

// Попередні оголошення шаблонних функцій.
template <typename T>
T Sqr(const T& value);

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& value);

template <typename T>
vector<T> Sqr(const vector<T>& values);

template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& values);

// Базовий випадок: число або інший тип, для якого визначено operator*.
template <typename T>
T Sqr(const T& value)
{
    return value * value;
}

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& value)
{
    return {Sqr(value.first), Sqr(value.second)};
}

template <typename T>
vector<T> Sqr(const vector<T>& values)
{
    vector<T> result;
    result.reserve(values.size());

    for (const T& value : values)
        result.push_back(Sqr(value));

    return result;
}

template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& values)
{
    map<Key, Value> result;

    for (const auto& item : values)
        result.emplace(item.first, Sqr(item.second));

    return result;
}

int main()
{
    vector<int> numbers = {1, 2, 3};
    cout << "vector:";
    for (int value : Sqr(numbers))
        cout << ' ' << value;
    cout << endl;

    map<int, pair<int, int>> mapOfPairs =
    {
        {4, {2, 2}},
        {7, {4, 3}}
    };

    cout << "map of pairs:" << endl;
    for (const auto& item : Sqr(mapOfPairs))
    {
        cout << item.first << ' '
             << item.second.first << ' '
             << item.second.second << endl;
    }

    return 0;
}
