#ifndef Bus_H
#define Bus_H

#include <iostream>
#include <vector>
#include "Driver.h"
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    class Bus  {
        private:
            string id;
            int8_t seats;
            vector<BusAmenities> amenities;
            ServiceType serviceType;
            Driver* driver;
        public:
            Bus();
            Bus(string _id, int8_t _seats, vector<BusAmenities> _amenities, ServiceType _serviceType, Driver* _driver);

            string getId();
            int8_t getSeats();
            vector<BusAmenities> getAmenities();
            ServiceType getServiceType();
            Driver* getDriver();

            void setId(string _id);
            void setSeats(int8_t _seats);
            void setAmenities(vector<BusAmenities> _amenities);
            void setServiceType(ServiceType _serviceType);
            void setDriver(Driver* _driver);
    };
};

#endif