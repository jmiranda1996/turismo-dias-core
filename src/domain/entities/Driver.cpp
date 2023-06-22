#include <iostream>
#include "Driver.h"
#include "DriverInfo.h"
#include "../shared/User.h"
#include "../shared/UserInfo.h"
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    Driver::Driver(): User() {
        driverInfo = nullptr;
    };
    Driver::Driver(
        string _documentId, 
        DocumentType _documentType,
        string _username, 
        string _emailAddress, 
        DriverInfo* _driverInfo, 
        UserInfo* _userInfo
    ): User(_documentId, _documentType, _username, _emailAddress, _userInfo) {
        driverInfo = _driverInfo;
    };

    DriverInfo* Driver::getDriverInfo() { return driverInfo; };

    void Driver::setDriverInfo(DriverInfo* _driverInfo) { driverInfo = _driverInfo; };
};