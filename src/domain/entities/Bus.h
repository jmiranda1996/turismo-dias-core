#include <iostream>
#include "Driver.h"
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    class Bus  {
        private:
            string id;
            int8_t seats;
            BusAmenities amenities[4];
            ServiceType serviceType;
            Driver* driver;
        public:
            Bus();
            Bus(string _id, int8_t _seats, BusAmenities _amenities[4], ServiceType _serviceType, Driver* _driver);

            string getId();
            int8_t getSeats();
            BusAmenities* getAmenities();
            ServiceType getServiceType();
            Driver* getDriver();

            void setId(string _id);
            void setSeats(int8_t _seats);
            void setAmenities(BusAmenities _amenities[4]);
            void setServiceType(ServiceType _serviceType);
            void setDriver(Driver* _driver);
    };
};