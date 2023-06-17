#include <iostream>
#include "Bus.h"
#include "Agency.h"
#include "../shared/Stopover.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    class Schedule  {
        private:
            string id;
            string from;
            string to;
            time_t departureDate;
            time_t returnDate;
            float price;
            Bus* bus;
            Agency* inbound;
            Agency* outbound;
            Stopover** stopovers;
        public:
            Schedule();
            Schedule(
                string _id,
                string _from,
                string _to,
                time_t _departureDate,
                time_t _returnDate,
                float _price,
                Bus* _bus,
                Agency* _inbound = nullptr,
                Agency* _outbound = nullptr,
                Stopover** _stopovers = nullptr
            );

            string getId();
            string getFrom();
            string getTo();
            time_t getDepartureDate();
            time_t getReturnDate();
            float getPrice();
            Bus* getBus();
            Agency* getInbound();
            Agency* getOutbound();
            Stopover** getStopovers();

            void setId(string _id);
            void setFrom(string _from);
            void setTo(string _to);
            void setDepartureDate(time_t _departureDate);
            void setReturnDate(time_t _returnDate);
            void setPrice(float _price);
            void setBus(Bus* _bus);
            void setInbound(Agency* _inbound);
            void setOutbound(Agency* _outbound);
            void setStopovers(Stopover** _stopovers);
    };
};