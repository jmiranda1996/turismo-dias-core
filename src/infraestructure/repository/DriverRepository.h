#ifndef DriverRepository_H
#define DriverRepository_H

#include <iostream>
#include "../structures/HashTable.h"
#include "../structures/LinkedList.h"
#include "../../domain/interfaces/GenericInterface.h"
#include "../../domain/entities/Booking.h"
 
using namespace std;
using namespace tdc::domain;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    class DriverRepository {
        private:
            HashTable<entities::Driver>* drivers;
        protected:
            DriverRepository() {
                drivers = new structures::HashTable<entities::Driver>(50000);
            }
            static DriverRepository* singleton;
        public:
            DriverRepository(DriverRepository &other) = delete;
            void operator=(const DriverRepository &) = delete;
            static DriverRepository *GetInstance();

            LinkedList<entities::Driver> getAll();
            entities::Driver get(uint key);
            void insertOrUpdate(entities::Driver* newEntity);
            void remove(uint key);
            uint count();
    };
};

#endif