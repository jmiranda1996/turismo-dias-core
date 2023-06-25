#include <iostream>
#include "DriverInfo.h"

using namespace std;

namespace tdc::domain::entities {
    DriverInfo::DriverInfo() {
        driverLicense = "";
        issue = time(0);
        expiration = time(0);
    };
    DriverInfo::DriverInfo(string _driverLicense, time_t _issue, time_t _expiration) {
        driverLicense = _driverLicense;
        issue = _issue;
        expiration = _expiration;
    };

    string DriverInfo::getDriverLicense() { return driverLicense; };
    time_t DriverInfo::getIssue() { return issue; };
    time_t DriverInfo::getExpiration() { return expiration; };

    void DriverInfo::setDriverLicense(string _driverLicense) { driverLicense = _driverLicense; };
    void DriverInfo::setIssue(time_t _issue) { issue = _issue; };
    void DriverInfo::setExpiration(time_t _expiration) { expiration = _expiration; };
};