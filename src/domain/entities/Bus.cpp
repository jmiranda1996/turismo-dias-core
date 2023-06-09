#include <iostream>
#include <vector>
#include "Bus.h"
#include "Driver.h"
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    Bus::Bus() {
        id = "";
        seats = 0;
        serviceType = Express;
        driver = nullptr;
    };
    Bus::Bus(string _id, int _seats, vector<BusAmenities> _amenities, ServiceType _serviceType, Driver* _driver) {
        id = _id;
        seats = _seats;
        amenities = _amenities;
        serviceType = _serviceType;
        driver = _driver;
    };

    string Bus::getId() { return id; }
    int Bus::getSeats() { return seats; }
    vector<BusAmenities> Bus::getAmenities() { return amenities; }
    ServiceType Bus::getServiceType() { return serviceType; }
    Driver* Bus::getDriver() { return driver; }

    void Bus::setId(string _id) { id = _id; };
    void Bus::setSeats(int _seats) { seats = _seats; };
    void Bus::setAmenities(vector<BusAmenities> _amenities) { amenities = _amenities; };
    void Bus::setServiceType(ServiceType _serviceType) { serviceType = _serviceType; };
    void Bus::setDriver(Driver* _driver) { driver = _driver; };
};