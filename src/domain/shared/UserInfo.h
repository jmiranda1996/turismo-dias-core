#ifndef UserInfo_H
#define UserInfo_H

#include <iostream>

using namespace std;

namespace tdc::domain::shared {
    class UserInfo {
        private:
            string phoneNumber;
            string address;
            string zipCode;
            string country;
            string city;
            string firstName;
            string lastName;
            time_t birthday;
            char gender;
        public:
            UserInfo();
            UserInfo(
                string _phoneNumber, 
                string _address, 
                string _zipCode, 
                string _country, 
                string _city,
                string _firstName, 
                string _lastName,
                time_t _birthday,
                char _gender
            );

            string getPhoneNumber();
            string getAddress();
            string getZipCode();
            string getCountry();
            string getCity();
            string getFirstName();
            string getLastName();
            time_t getBirthday();
            char getGender();

            void setPhoneNumber(string _phoneNumber);
            void setAddress(string _address);
            void setZipCode(string _zipCode);
            void setCountry(string _country);
            void setCity(string _city);
            void setFirstName(string _firstName);
            void setLastName(string _lastName);
            void setBirthday(time_t _birthday);
            void setGender(char _gender);
    };
};

#endif