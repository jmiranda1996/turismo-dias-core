#ifndef PassengerRepository_H
#define PassengerRepository_H

#include <iostream>
#include "../structures/HashTable.h"
#include "../structures/LinkedList.h"
#include "../../domain/interfaces/GenericInterface.h"
#include "../../domain/entities/Passenger.h"
 
using namespace std;
using namespace tdc::domain;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    class PassengerRepository {
        private:
            HashTable<entities::Passenger>* passengers;
        protected:
            PassengerRepository() {
                passengers = new structures::HashTable<entities::Passenger>(50000);
            }
            static PassengerRepository* singleton;
        public:
            PassengerRepository(PassengerRepository &other) = delete;
            void operator=(const PassengerRepository &) = delete;
            static PassengerRepository *GetInstance();

            LinkedList<entities::Passenger> getAll();
            entities::Passenger get(int key);
            void insertOrUpdate(entities::Passenger* newEntity);
            void remove(int key);
            int count();
    };
};

#endif