#ifndef DataManager_H
#define DataManager_H

#include <iostream>
 
using namespace std;

namespace tdc::infraestructure {
    class DataManager {
        private:
            string filename;
        public:
            DataManager();
            DataManager(string _filename);
            void loadData();
    };
}

#endif