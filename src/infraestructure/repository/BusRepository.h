#ifndef BusRepository_H
#define BusRepository_H

#include <iostream>
#include "../structures/HashTable.h"
#include "../structures/LinkedList.h"
#include "../../domain/interfaces/GenericInterface.h"
#include "../../domain/entities/Bus.h"
 
using namespace std;
using namespace tdc::domain;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    class BusRepository {
        private:
            HashTable<entities::Bus>* buses;
        protected:
            BusRepository() {
                buses = new structures::HashTable<entities::Bus>(50000);
            }
            static BusRepository* singleton;
        public:
            BusRepository(BusRepository &other) = delete;
            void operator=(const BusRepository &) = delete;
            static BusRepository *GetInstance();

            LinkedList<entities::Bus> getAll();
            entities::Bus get(uint key);
            void insertOrUpdate(entities::Bus* newEntity);
            void remove(uint key);
            uint count();
    };
};

#endif