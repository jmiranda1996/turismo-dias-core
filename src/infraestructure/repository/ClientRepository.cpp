#include <iostream>
#include "ClientRepository.h"
#include "../structures/HashTable.h"
#include "../common/Utils.h"
#include "../../domain/entities/Client.h"
 
using namespace std;
using namespace tdc::domain::shared;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    ClientRepository* ClientRepository::singleton= nullptr;
    
    ClientRepository* ClientRepository::GetInstance() {
        if(singleton == nullptr){
            singleton = new ClientRepository();
        }
        return singleton;
    }

    entities::Client ClientRepository::get(uint key) {
        return *clients->get(key);
    }

    void ClientRepository::insertOrUpdate(entities::Client* newEntity) {
        uint newKey = Utils::hashFunction(newEntity->getDocumentId(), clients->getMaxSize());
        clients->insert(newKey, newEntity);
    }

    void ClientRepository::remove(uint key) {
        clients->remove(key);
    }
};