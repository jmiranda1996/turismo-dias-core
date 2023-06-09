#include <iostream>
#include "Agency.h"

using namespace std;

namespace tdc::domain::entities {
    Agency::Agency() {
        id = "";
        address = "";
        zipCode = "";
        country = "";
        phoneNumber = "";
        city = "";
        terminalName = "";
    };
    Agency::Agency(
        string _id,
        string _address,
        string _zipCode,
        string _country,
        string _phoneNumber,
        string _city,
        string _terminalName
    ) {
        id = _id;
        address = _address;
        zipCode = _zipCode;
        country = _country;
        phoneNumber = _phoneNumber;
        city = _city;
        terminalName = _terminalName;
    };

    string Agency::getId() { return id; };
    string Agency::getAddress() { return address; };
    string Agency::getZipCode() { return zipCode; };
    string Agency::getCountry() { return country; };
    string Agency::getPhoneNumber() { return phoneNumber; };
    string Agency::getCity() { return city; };
    string Agency::getTerminalName() { return terminalName; };

    void Agency::setId(string _id) { id = _id; };
    void Agency::setAddress(string _address) { address = _address; };
    void Agency::setZipCode(string _zipCode) { zipCode = _zipCode; };
    void Agency::setCountry(string _country) { country = _country; };
    void Agency::setPhoneNumber(string _phoneNumber) { phoneNumber = _phoneNumber; };
    void Agency::setCity(string _city) { city = _city; };
    void Agency::setTerminalName(string _terminalName) { terminalName = _terminalName; };
};