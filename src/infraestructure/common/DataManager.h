#ifndef DataManager_H
#define DataManager_H

#include <iostream>
 
using namespace std;

namespace tdc::infraestructure::common {
    class DataManager {
        public:
            static void loadData(string _filename);
            static void loadAdmin(string _filename);
            static void loadAgencies(string _filename);
            static void loadBooking(string _filename);
            static void loadBus(string _filename);
            static void loadClient(string _filename);
            static void loadContactForm(string _filename);
            static void loadDriver(string _filename);
            static void loadSchedule(string _filename);
    };
}

#endif