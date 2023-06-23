#ifndef ClientRepository_H
#define ClientRepository_H

#include <iostream>
#include "../structures/HashTable.h"
#include "../../domain/interfaces/GenericInterface.h"
#include "../../domain/entities/Client.h"
 
using namespace std;
using namespace tdc::domain;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    class ClientRepository {
        private:
            HashTable<entities::Client>* clients;
        public:
            ClientRepository();
            entities::Client* get(uint key);
            void insertOrUpdate(entities::Client* newEntity);
            void remove(uint key);
    };
};

#endif