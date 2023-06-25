#ifndef Booking_H
#define Booking_H

#include <iostream>
#include <vector>
#include "Client.h"
#include "Schedule.h"
#include "BookingPayInfo.h"
#include "Passenger.h"
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    class Booking {
        private:
            string id;
            Client* client;
            Schedule* schedule;
            uint8_t passengers;
            vector<uint8_t> seats;
            Passenger** passengersInfo;
            time_t bookingDate;
            time_t cancelledDate;
            BookingPayInfo* bookingPayInfo;
            BookingStatus status;
        public:
            Booking();
            Booking(
                string _id,
                Client* _client, 
                Schedule* _schedule, 
                uint8_t _passengers, 
                vector<uint8_t> _seats,
                time_t _bookingDate,
                Passenger** _passengersInfo,
                BookingPayInfo* _bookingPayInfo,
                BookingStatus _status = Pending
            );

            string getId();
            Client* getClient();
            Schedule* getSchedule();
            uint8_t getPassengers();
            vector<uint8_t> getSeats();
            time_t getBookingDate();
            time_t getCancelledDate();
            Passenger** getPassengersInfo();
            BookingPayInfo* getBookingPayInfo();
            BookingStatus getStatus();

            void setId(string _id);
            void setClient(Client* _client);
            void setSchedule(Schedule* _schedule);
            void setPassengers(uint8_t _passengers);
            void setSeats(vector<uint8_t> _seats);
            void setBookingDate(time_t _bookingDate);
            void setCancelledDate(time_t _cancelledDate);
            void setPassengersInfo(Passenger** _passengersInfo);
            void setBookingPayInfo(BookingPayInfo* _bookingPayInfo);
            void setStatus(BookingStatus _status);
    };
}

#endif