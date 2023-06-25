#include <iostream>
#include "ClientRepository.h"
#include "../structures/HashTable.h"
#include "../common/Utils.h"
#include "../../domain/entities/Client.h"
 
using namespace std;
using namespace tdc::domain::entities;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    ClientRepository* ClientRepository::singleton= nullptr;
    
    ClientRepository* ClientRepository::GetInstance() {
        if(singleton == nullptr){
            singleton = new ClientRepository();
        }
        return singleton;
    }

    LinkedList<Client> ClientRepository::getAll() {
        int maxSize = clients->getMaxSize();
        LinkedList<Client> list;
        for (uint i = 0; i < maxSize; i++)
        {
            Client* client = clients->get(i);
            if (client != nullptr)
                list.insert(*client);
        }
        return list;
    }

    entities::Client ClientRepository::get(uint key) {
        return *clients->get(key);
    }

    void ClientRepository::insertOrUpdate(Client* newEntity) {
        uint newKey = Utils::hashFunction(newEntity->getDocumentId(), clients->getMaxSize());
        clients->insert(newKey, newEntity);
    }

    void ClientRepository::remove(uint key) {
        clients->remove(key);
    }
};