#ifndef Driver_H
#define Driver_H

#include <iostream>
#include "DriverInfo.h"
#include "../shared/User.h"
#include "../shared/UserInfo.h"
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    class Driver: public User  {
        private:
            DriverInfo* driverInfo;
        public:
            Driver();
            Driver(
                string _documentId, 
                DocumentType _documentType,
                string _username, 
                string _emailAddress, 
                DriverInfo* _driverInfo = nullptr, 
                UserInfo* _userInfo = nullptr
            );

            DriverInfo* getDriverInfo();

            void setDriverInfo(DriverInfo* _driverInfo);
    };
};

#endif