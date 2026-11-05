#pragma once

#include <string>

class PhoneNumber
{
public:
    explicit PhoneNumber(const std::string& internationalNumber);

    std::string GetCountryCode() const;
    std::string GetCityCode() const;
    std::string GetLocalNumber() const;
    std::string GetInternationalNumber() const;

private:
    std::string countryCode_;
    std::string cityCode_;
    std::string localNumber_;
};
