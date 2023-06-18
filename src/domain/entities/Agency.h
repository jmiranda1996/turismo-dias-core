#ifndef Agency_H
#define Agency_H

#include <iostream>

using namespace std;

namespace tdc::domain::entities {
    class Agency  {
        private:
            string id;
            string address;
            string zipCode;
            string country;
            string phoneNumber;
            string city;
            string terminalName;
        public:
            Agency();
            Agency(
                string _id,
                string _address,
                string _zipCode,
                string _country,
                string _phoneNumber,
                string _city,
                string _terminalName
            );

            string getId();
            string getAddress();
            string getZipCode();
            string getCountry();
            string getPhoneNumber();
            string getCity();
            string getTerminalName();

            void setId(string _id);
            void setAddress(string _address);
            void setZipCode(string _zipCode);
            void setCountry(string _country);
            void setPhoneNumber(string _phoneNumber);
            void setCity(string _city);
            void setTerminalName(string _terminalName);
    };
};

#endif