#include <iostream>
#include "UserInfo.h"

using namespace std;

namespace tdc::domain::shared {
    UserInfo::UserInfo() {
        phoneNumber = "";
        address = "";
        zipCode = "";
        country = "";
        city = "";
        firstName = "";
        lastName = "";
        birthday = time(0);
        gender = 'U';
    };
    UserInfo::UserInfo(
        string _phoneNumber, 
        string _address, 
        string _zipCode, 
        string _country, 
        string _city,
        string _firstName, 
        string _lastName,
        time_t _birthday,
        char _gender
    ) { 
        phoneNumber = _phoneNumber;
        address = _address;
        zipCode = _zipCode;
        country = _country;
        city = _city;
        firstName = _firstName;
        lastName = _lastName;
        birthday = _birthday;
        gender = _gender;
    };

    string UserInfo::getPhoneNumber() { return phoneNumber; }
    string UserInfo::getAddress() { return address; }
    string UserInfo::getZipCode() { return zipCode; }
    string UserInfo::getCountry() { return country; }
    string UserInfo::getCity() { return city; }
    string UserInfo::getFirstName() { return firstName; }
    string UserInfo::getLastName() { return lastName; }
    time_t UserInfo::getBirthday() { return birthday; }
    char UserInfo::getGender() { return gender; }

    void UserInfo::setPhoneNumber(string _phoneNumber) { phoneNumber = _phoneNumber; };
    void UserInfo::setAddress(string _address) { address = _address; };
    void UserInfo::setZipCode(string _zipCode) { zipCode = _zipCode; };
    void UserInfo::setCountry(string _country) { country = _country; };
    void UserInfo::setCity(string _city) { city = _city; };
    void UserInfo::setFirstName(string _firstName) { firstName = _firstName; };
    void UserInfo::setLastName(string _lastName) { lastName = _lastName; };
    void UserInfo::setBirthday(time_t _birthday) { birthday = _birthday; };
    void UserInfo::setGender(char _gender) { gender = _gender; };
};