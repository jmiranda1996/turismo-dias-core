#include <iostream>
#include "DriverRepository.h"
#include "../structures/HashTable.h"
#include "../structures/LinkedList.h"
#include "../common/Utils.h"
#include "../../domain/entities/Driver.h"
 
using namespace std;
using namespace tdc::domain;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    DriverRepository* DriverRepository::singleton= nullptr;
    
    DriverRepository* DriverRepository::GetInstance() {
        if(singleton == nullptr){
            singleton = new DriverRepository();
        }
        return singleton;
    }

    LinkedList<entities::Driver> DriverRepository::getAll() {
        int maxSize = drivers->getMaxSize();
        LinkedList<entities::Driver> list;
        for (int i = 0; i < maxSize; i++)
        {
            entities::Driver* Driver = drivers->get(i);
            if (Driver != nullptr)
                list.insert(*Driver);
        }
        return list;
    }

    entities::Driver DriverRepository::get(int key) {
        return *drivers->get(key);
    }

    void DriverRepository::insertOrUpdate(entities::Driver* newEntity) {
        int newKey = Utils::hashFunction(newEntity->getDocumentId(), drivers->getMaxSize());
        drivers->insert(newKey, newEntity);
    }

    void DriverRepository::remove(int key) {
        drivers->remove(key);
    }

    int DriverRepository::count() {
        return drivers->getSize();
    }
};