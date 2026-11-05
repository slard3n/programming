#include <iostream>
#include <numeric>
#include <sstream>

using namespace std;

class Rational
{
public:
    Rational() : numerator_(0), denominator_(1)
    {
    }

    Rational(int numerator, int denominator)
    {
        Normalize(numerator, denominator);
    }

    int Numerator() const
    {
        return numerator_;
    }

    int Denominator() const
    {
        return denominator_;
    }

private:
    int numerator_;
    int denominator_;

    void Normalize(int numerator, int denominator)
    {
        if (denominator == 0)
        {
            numerator_ = 0;
            denominator_ = 1;
            return;
        }

        if (numerator == 0)
        {
            numerator_ = 0;
            denominator_ = 1;
            return;
        }

        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }

        const int divisor = gcd(numerator < 0 ? -numerator : numerator,
                                denominator);
        numerator_ = numerator / divisor;
        denominator_ = denominator / divisor;
    }
};

bool operator==(const Rational& left, const Rational& right)
{
    return left.Numerator() == right.Numerator()
        && left.Denominator() == right.Denominator();
}

Rational operator+(const Rational& left, const Rational& right)
{
    return Rational(left.Numerator() * right.Denominator()
                        + right.Numerator() * left.Denominator(),
                    left.Denominator() * right.Denominator());
}

Rational operator-(const Rational& left, const Rational& right)
{
    return Rational(left.Numerator() * right.Denominator()
                        - right.Numerator() * left.Denominator(),
                    left.Denominator() * right.Denominator());
}

Rational operator*(const Rational& left, const Rational& right)
{
    return Rational(left.Numerator() * right.Numerator(),
                    left.Denominator() * right.Denominator());
}

Rational operator/(const Rational& left, const Rational& right)
{
    return Rational(left.Numerator() * right.Denominator(),
                    left.Denominator() * right.Numerator());
}

ostream& operator<<(ostream& stream, const Rational& value)
{
    stream << value.Numerator() << '/' << value.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& value)
{
    int numerator;
    int denominator;
    char separator;

    if (!(stream >> numerator))
        return stream;

    if (!(stream >> separator) || separator != '/')
    {
        stream.setstate(ios::failbit);
        return stream;
    }

    if (!(stream >> denominator) || denominator == 0)
    {
        stream.setstate(ios::failbit);
        return stream;
    }

    value = Rational(numerator, denominator);
    return stream;
}

int main()
{
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10)
            return 1;
    }
    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3)
            return 2;
    }
    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3)
            return 3;
    }
    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3)
            return 4;
    }
    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1)
            return 5;
    }
    {
        const Rational r;
        if (r.Numerator() != 0 || r.Denominator() != 1)
            return 6;
    }
    if (!(Rational(4, 6) == Rational(2, 3)))
        return 7;
    if (!(Rational(2, 3) + Rational(4, 3) == Rational(2, 1)))
        return 8;
    if (!(Rational(5, 7) - Rational(2, 9) == Rational(31, 63)))
        return 9;
    if (!(Rational(2, 3) * Rational(4, 3) == Rational(8, 9)))
        return 10;
    if (!(Rational(5, 4) / Rational(15, 8) == Rational(2, 3)))
        return 11;

    ostringstream output;
    output << Rational(-6, 8);
    if (output.str() != "-3/4")
        return 12;

    istringstream input("5/7 10/8");
    Rational first;
    Rational second;
    input >> first >> second;
    if (!(first == Rational(5, 7) && second == Rational(5, 4)))
        return 13;

    istringstream invalid("1*2");
    Rational unchanged;
    invalid >> unchanged;
    if (!(unchanged == Rational()))
        return 14;

    cout << "OK" << endl;
    return 0;
}
