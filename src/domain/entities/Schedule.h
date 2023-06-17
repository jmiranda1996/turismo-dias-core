#include <iostream>
#include "Bus.h"
// #include "../shared/Enums.h"

using namespace std;
// using namespace tdc::domain::shared;

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
            // string stopovers[];
            /*
            inbound
            onbound
            */
        public:
            Schedule();
            Schedule(
                string _id,
                string _from,
                string _to,
                time_t _departureDate,
                time_t _returnDate,
                float _price,
                Bus* _bus
            );

            string getId();
            string getFrom();
            string getTo();
            time_t getDepartureDate();
            time_t getReturnDate();
            float getPrice();
            Bus* getBus();

            void setId(string _id);
            void setFrom(string _from);
            void setTo(string _to);
            void setDepartureDate(time_t _departureDate);
            void setReturnDate(time_t _returnDate);
            void setPrice(float _price);
            void setBus(Bus* _bus); 
    };
};