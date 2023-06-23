#include <iostream>
#include "ClientRepository.h"
#include "../structures/HashTable.h"
#include "../common/utils.hpp"
#include "../../domain/entities/Client.h"
 
using namespace std;
using namespace tdc::domain::shared;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    ClientRepository::ClientRepository() {
        // HashTable<int>* a = new HashTable<int>(40);
        clients = new structures::HashTable<entities::Client>(50000);
    }

    entities::Client* ClientRepository::get(uint key) {
        return clients->get(key);
    }

    void ClientRepository::insertOrUpdate(entities::Client* newEntity) {
        uint newKey = hashFunction(newEntity->getDocumentId(), clients->getMaxSize());
        cout << "New Key: " << newKey << endl;
        clients->insert(newKey, newEntity);
    }

    void ClientRepository::remove(uint key) {
        clients->remove(key);
    }
};