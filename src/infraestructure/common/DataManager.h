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
            static void loadContactForm(string _filename);
    };
}

#endif