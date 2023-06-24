#include <iostream>
#include "PassengerRepository.h"
#include "../structures/HashTable.h"
#include "../structures/LinkedList.h"
#include "../common/Utils.h"
#include "../../domain/entities/Passenger.h"
 
using namespace std;
using namespace tdc::domain;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    PassengerRepository* PassengerRepository::singleton= nullptr;
    
    PassengerRepository* PassengerRepository::GetInstance() {
        if(singleton == nullptr){
            singleton = new PassengerRepository();
        }
        return singleton;
    }

    LinkedList<entities::Passenger> PassengerRepository::getAll() {
        int maxSize = passengers->getMaxSize();
        LinkedList<entities::Passenger> list;
        for (uint i = 0; i < maxSize; i++)
        {
            entities::Passenger* Passenger = passengers->get(i);
            if (Passenger != nullptr)
                list.insert(*Passenger);
        }
        return list;
    }

    entities::Passenger PassengerRepository::get(uint key) {
        return *passengers->get(key);
    }

    void PassengerRepository::insertOrUpdate(entities::Passenger* newEntity) {
        uint newKey = Utils::hashFunction(newEntity->getDocumentId(), passengers->getMaxSize());
        passengers->insert(newKey, newEntity);
    }

    void PassengerRepository::remove(uint key) {
        passengers->remove(key);
    }

    uint PassengerRepository::count() {
        return passengers->getSize();
    }
};