#include <iostream>
#include "BusRepository.h"
#include "../structures/HashTable.h"
#include "../structures/LinkedList.h"
#include "../common/Utils.h"
#include "../../domain/entities/Bus.h"
 
using namespace std;
using namespace tdc::domain;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    BusRepository* BusRepository::singleton= nullptr;
    
    BusRepository* BusRepository::GetInstance() {
        if(singleton == nullptr){
            singleton = new BusRepository();
        }
        return singleton;
    }

    LinkedList<entities::Bus> BusRepository::getAll() {
        int maxSize = buses->getMaxSize();
        LinkedList<entities::Bus> list;
        for (int i = 0; i < maxSize; i++)
        {
            entities::Bus* Bus = buses->get(i);
            if (Bus != nullptr)
                list.insert(*Bus);
        }
        return list;
    }

    entities::Bus BusRepository::get(int key) {
        return *buses->get(key);
    }

    void BusRepository::insertOrUpdate(entities::Bus* newEntity) {
        int newKey = Utils::hashFunction(newEntity->getId(), buses->getMaxSize());
        buses->insert(newKey, newEntity);
    }

    void BusRepository::remove(int key) {
        buses->remove(key);
    }

    int BusRepository::count() {
        return buses->getSize();
    }
};