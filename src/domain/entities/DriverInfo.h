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
    };
};