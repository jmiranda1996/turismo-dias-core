#include <iostream>
#include "Booking.h"
#include "Client.h"
#include "Schedule.h"
#include "BookingPayInfo.h"
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    Booking::Booking() {
        Client* client = nullptr;
        Schedule* schedule = nullptr;
        uint8_t passengers = 0;
        bookingDate = time(0);
        cancelledDate = time(NULL);
        BookingPayInfo* bookingPayInfo = nullptr;
        BookingStatus status = Pending;
    };
    Booking::Booking(
        string _id,
        Client* _client, 
        Schedule* _schedule, 
        uint8_t _passengers, 
        vector<uint8_t> _seats,
        time_t _bookingDate,
        Passenger** _passengersInfo,
        BookingPayInfo* _bookingPayInfo,
        BookingStatus _status
    ) {
        id = _id;
        client = _client;
        schedule = _schedule;
        passengers = _passengers;
        seats = _seats;
        bookingDate = _bookingDate;
        cancelledDate = time(0);
        passengersInfo = _passengersInfo;
        bookingPayInfo = _bookingPayInfo;
        status = _status;
    };


    string Booking::getId() { return id; };
    Client* Booking::getClient() { return client; };
    Schedule* Booking::getSchedule() { return schedule; };
    uint8_t Booking::getPassengers() { return passengers; };
    vector<uint8_t> Booking::getSeats() { return seats; };
    time_t Booking::getBookingDate() { return bookingDate; };
    time_t Booking::getCancelledDate() { return cancelledDate; };
    Passenger** Booking::getPassengersInfo() { return passengersInfo; };
    BookingPayInfo* Booking::getBookingPayInfo() { return bookingPayInfo; };
    BookingStatus Booking::getStatus() { return status; };

    void Booking::setId(string _id) { id = _id; };
    void Booking::setClient(Client* _client) { client = _client; };
    void Booking::setSchedule(Schedule* _schedule) { schedule = _schedule; };
    void Booking::setPassengers(uint8_t _passengers) { passengers = _passengers; };
    void Booking::setSeats(vector<uint8_t> _seats) { seats = _seats; };
    void Booking::setBookingDate(time_t _bookingDate) { bookingDate = _bookingDate; };
    void Booking::setCancelledDate(time_t _cancelledDate) { cancelledDate = _cancelledDate; };
    void Booking::setPassengersInfo(Passenger** _passengersInfo) { passengersInfo = _passengersInfo; };
    void Booking::setBookingPayInfo(BookingPayInfo* _bookingPayInfo) { bookingPayInfo = _bookingPayInfo; };
    void Booking::setStatus(BookingStatus _status) { status = _status; };
};