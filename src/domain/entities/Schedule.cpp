#include <iostream>
#include "Schedule.h"
#include "Bus.h"
#include "Agency.h"
#include "../shared/Stopover.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    Schedule::Schedule() {
        id = "";
        from = "";
        to = "";
        departureDate = time(0);
        returnDate = time(0);
        price = 0;
        bus = nullptr;
        inbound = nullptr;
        outbound = nullptr;
        stopovers = nullptr;
    };
    Schedule::Schedule(
        string _id,
        string _from,
        string _to,
        time_t _departureDate,
        time_t _returnDate,
        float _price,
        Bus* _bus,
        Agency* _inbound,
        Agency* _outbound,
        Stopover** _stopovers
    ) {
        id = _id;
        from = _from;
        to = _to;
        departureDate = _departureDate;
        returnDate = _returnDate;
        price = _price;
        bus = _bus;
        inbound = _inbound;
        outbound = _outbound;
        stopovers = _stopovers;
    };

    string Schedule::getId() { return id; };
    string Schedule::getFrom() { return from; };
    string Schedule::getTo() { return to; };
    time_t Schedule::getDepartureDate() { return departureDate; };
    time_t Schedule::getReturnDate() { return returnDate; };
    float Schedule::getPrice() { return price; };
    Bus* Schedule::getBus() { return bus; };
    Agency* Schedule::getInbound() { return inbound; };
    Agency* Schedule::getOutbound() { return outbound; };
    Stopover** Schedule::getStopovers() { return stopovers; };

    void Schedule::setId(string _id) { id = _id; };
    void Schedule::setFrom(string _from) { from = _from; };
    void Schedule::setTo(string _to) { to = _to; };
    void Schedule::setDepartureDate(time_t _departureDate) { departureDate = _departureDate; };
    void Schedule::setReturnDate(time_t _returnDate) { returnDate = _returnDate; };
    void Schedule::setPrice(float _price) { price = _price; };
    void Schedule::setBus(Bus* _bus) { bus = _bus; };
    void Schedule::setInbound(Agency* _inbound) { inbound = _inbound; };
    void Schedule::setOutbound(Agency* _outbound) { outbound = _outbound; };
    void Schedule::setStopovers(Stopover** _stopovers) { stopovers = _stopovers; };
};