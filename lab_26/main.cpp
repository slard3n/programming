#include <iostream>
#include <stdexcept>

#include "phone_number.h"

using namespace std;

int main()
{
    try
    {
        PhoneNumber phone1("+38-067-7777");
        cout << phone1.GetInternationalNumber() << endl;
    }
    catch (const invalid_argument& ex)
    {
        cerr << ex.what() << endl;
    }

    try
    {
        PhoneNumber phone2("+38-067-aaaa");
        cout << phone2.GetInternationalNumber() << endl;
    }
    catch (const invalid_argument& ex)
    {
        cerr << ex.what() << endl;
    }

    try
    {
        PhoneNumber phone3("+380-67-aaaa");
        cout << phone3.GetInternationalNumber() << endl;
    }
    catch (const invalid_argument& ex)
    {
        cerr << ex.what() << endl;
    }

    try
    {
        PhoneNumber phone4("+3-7-aaaa");
        cout << phone4.GetInternationalNumber() << endl;
    }
    catch (const invalid_argument& ex)
    {
        cerr << ex.what() << endl;
    }

    try
    {
        PhoneNumber phone5("380-67-aaaa");
        cout << phone5.GetInternationalNumber() << endl;
    }
    catch (const exception& ex)
    {
        cerr << ex.what() << endl;
    }

    try
    {
        PhoneNumber phone6("+380-67-");
        cout << phone6.GetInternationalNumber() << endl;
    }
    catch (const exception& ex)
    {
        cerr << ex.what() << endl;
    }

    return 0;
}
