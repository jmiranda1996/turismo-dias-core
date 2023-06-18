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
};