#ifndef DriverInfo_H
#define DriverInfo_H

#include <iostream>

using namespace std;

namespace tdc::domain::entities {
    class DriverInfo {
        private:
            string driverLicense;
            time_t issue;
            time_t expiration;
        public:
            DriverInfo();
            DriverInfo(string _driverLicense, time_t _issue, time_t _expiration);

            string getDriverLicense();
            time_t getIssue();
            time_t getExpiration();

            void setDriverLicense(string _driverLicense);
            void setIssue(time_t _issue);
            void setExpiration(time_t _expiration);
    };
};

#endif