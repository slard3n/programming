#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    explicit Animal(const string& name) : Name(name)
    {
    }

    const string Name;
};

class Dog : public Animal
{
public:
    explicit Dog(const string& name) : Animal(name)
    {
    }

    void Bark() const
    {
        cout << Name << " barks: woof!" << endl;
    }
};

int main()
{
    Dog dog1("Rex");
    Dog dog2("Buddy");

    cout << "Dog name: " << dog1.Name << endl;
    dog1.Bark();
    dog2.Bark();

    return 0;
}
