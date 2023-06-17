#ifndef Enums_H
#define Enums_H

namespace tdc::domain::shared {
    enum UserType { Client, Administrator, Driver, Unknown };
    enum UserStatus { Inactive, Active, PendingConfirm };
    enum ServiceType { Express, Cruzero, Premiun };
    enum BusAmenities { Airco, Toilet, Tablet, WiFi };
    enum BookingStatus { Pending, Paid, Cancelled };
    enum PaymentMethod { Card, Yape, Paypal, Transfer, GiftCard };
};

#endif