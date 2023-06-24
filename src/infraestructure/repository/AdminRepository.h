#ifndef AdminRepository_H
#define AdminRepository_H

#include <iostream>
#include "../structures/HashTable.h"
#include "../structures/LinkedList.h"
#include "../../domain/interfaces/GenericInterface.h"
#include "../../domain/entities/Admin.h"
 
using namespace std;
using namespace tdc::domain;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    class AdminRepository {
        private:
            HashTable<entities::Admin>* admins;
        protected:
            AdminRepository() {
                admins = new structures::HashTable<entities::Admin>(50000);
            }
            static AdminRepository* singleton;
        public:
            AdminRepository(AdminRepository &other) = delete;
            void operator=(const AdminRepository &) = delete;
            static AdminRepository *GetInstance();

            LinkedList<entities::Admin> getAll();
            entities::Admin get(uint key);
            void insertOrUpdate(entities::Admin* newEntity);
            void remove(uint key);
            uint count();
    };
};

#endif