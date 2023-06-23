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
        protected:
            ClientRepository() {
                clients = new structures::HashTable<entities::Client>(50000);
            }
            static ClientRepository* singleton;
        public:
            ClientRepository(ClientRepository &other) = delete;
            void operator=(const ClientRepository &) = delete;
            static ClientRepository *GetInstance();
            
            entities::Client get(uint key);
            void insertOrUpdate(entities::Client* newEntity);
            void remove(uint key);
            uint count();
    };
};

#endif