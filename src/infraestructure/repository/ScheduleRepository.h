#ifndef PassengerRepository_H
#define PassengerRepository_H

#include <iostream>
#include "../structures/HashTable.h"
#include "../structures/LinkedList.h"
#include "../../domain/interfaces/GenericInterface.h"
#include "../../domain/entities/Schedule.h"
 
using namespace std;
using namespace tdc::domain;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    class ScheduleRepository {
        private:
            HashTable<entities::Schedule>* schedules;
        protected:
            ScheduleRepository() {
                schedules = new structures::HashTable<entities::Schedule>(50000);
            }
            static ScheduleRepository* singleton;
        public:
            ScheduleRepository(ScheduleRepository &other) = delete;
            void operator=(const ScheduleRepository &) = delete;
            static ScheduleRepository *GetInstance();

            LinkedList<entities::Schedule> getAll();
            entities::Schedule get(uint key);
            void insertOrUpdate(entities::Schedule* newEntity);
            void remove(uint key);
            uint count();
    };
};

#endif