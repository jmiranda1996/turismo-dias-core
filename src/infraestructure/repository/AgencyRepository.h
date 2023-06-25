#ifndef AgencyRepository_H
#define AgencyRepository_H

#include <iostream>
#include "../structures/HashTable.h"
#include "../structures/LinkedList.h"
#include "../../domain/interfaces/GenericInterface.h"
#include "../../domain/entities/Agency.h"
 
using namespace std;
using namespace tdc::domain;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    class AgencyRepository {
        private:
            HashTable<entities::Agency>* agencies;
        protected:
            AgencyRepository() {
                agencies = new structures::HashTable<entities::Agency>(50000);
            }
            static AgencyRepository* singleton;
        public:
            AgencyRepository(AgencyRepository &other) = delete;
            void operator=(const AgencyRepository &) = delete;
            static AgencyRepository *GetInstance();

            LinkedList<entities::Agency> getAll();
            entities::Agency get(int key);
            void insertOrUpdate(entities::Agency* newEntity);
            void remove(int key);
            int count();
    };
};

#endif