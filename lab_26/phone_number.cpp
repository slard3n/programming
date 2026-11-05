#include "phone_number.h"

#include <stdexcept>

using namespace std;

PhoneNumber::PhoneNumber(const string& internationalNumber)
{
    const string errorMessage =
        "Phone number must begin with '+' symbol and contain 3 "
        "parts separated by '-' symbol: " + internationalNumber;

    if (internationalNumber.empty() || internationalNumber[0] != '+')
        throw invalid_argument(errorMessage);

    const size_t firstDash = internationalNumber.find('-');
    const size_t secondDash = internationalNumber.find('-', firstDash + 1);

    if (firstDash == string::npos || secondDash == string::npos
        || firstDash <= 1 || secondDash == firstDash + 1
        || secondDash + 1 >= internationalNumber.size())
    {
        throw invalid_argument(errorMessage);
    }

    countryCode_ = internationalNumber.substr(1, firstDash - 1);
    cityCode_ = internationalNumber.substr(firstDash + 1,
                                           secondDash - firstDash - 1);
    localNumber_ = internationalNumber.substr(secondDash + 1);
}

string PhoneNumber::GetCountryCode() const
{
    return countryCode_;
}

string PhoneNumber::GetCityCode() const
{
    return cityCode_;
}

string PhoneNumber::GetLocalNumber() const
{
    return localNumber_;
}

string PhoneNumber::GetInternationalNumber() const
{
    return "+" + countryCode_ + "-" + cityCode_ + "-" + localNumber_;
}
