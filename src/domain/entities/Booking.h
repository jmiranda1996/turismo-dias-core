#include <iostream>
#include "Client.h"
#include "Schedule.h"
#include "BookingPayInfo.h"
#include "Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    class Booking {
        private:
            Client* client;
            Schedule* schedule;
            uint8_t passengers;
            uint8_t* seats;
            // passengers info
            BookingPayInfo* bookingPayInfo;
            BookingStatus status;
        public:
            Booking();
            Booking(
                Client* _client, 
                Schedule* schedule, 
                uint8_t _passengers, 
                uint8_t* _seats,
                BookingPayInfo* _bookingPayInfo,
                BookingStatus _status = Pending
            );

            Client* getClient();
            Schedule* getSchedule();
            uint8_t getPassengers();
            uint8_t* getSeats();
            BookingPayInfo* getBookingPayInfo();
            BookingStatus getStatus();

            void setClient(Client* _client);
            void setSchedule(Schedule* schedule);
            void setPassengers(uint8_t _passengers);
            void setSeats(uint8_t* _seats);
            void setBookingPayInfo(BookingPayInfo* _bookingPayInfo);
            void setStatus(BookingStatus _status);
    };
};