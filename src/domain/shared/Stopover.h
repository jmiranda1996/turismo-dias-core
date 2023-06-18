#ifndef Stopover_H
#define Stopover_H

#include <iostream>

using namespace std;

namespace tdc::domain::shared {
    class Stopover
    {
        private:
            string address;
            string city;
        public:
            Stopover();
            Stopover(string _address, string _city);

            string getAddress();
            string getCity();

            void setAddress(string _address);
            void setCity(string _city);
    };
};

#endif