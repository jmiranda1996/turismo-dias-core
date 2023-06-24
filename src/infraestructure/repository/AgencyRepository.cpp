#include <iostream>
#include "AgencyRepository.h"
#include "../structures/HashTable.h"
#include "../structures/LinkedList.h"
#include "../common/Utils.h"
#include "../../domain/entities/Agency.h"
 
using namespace std;
using namespace tdc::domain;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    AgencyRepository* AgencyRepository::singleton= nullptr;
    
    AgencyRepository* AgencyRepository::GetInstance() {
        if(singleton == nullptr){
            singleton = new AgencyRepository();
        }
        return singleton;
    }

    LinkedList<entities::Agency> AgencyRepository::getAll() {
        int maxSize = agencies->getMaxSize();
        LinkedList<entities::Agency> list;
        for (uint i = 0; i < maxSize; i++)
        {
            entities::Agency* Agency = agencies->get(i);
            if (Agency != nullptr)
                list.insert(*Agency);
        }
        return list;
    }

    entities::Agency AgencyRepository::get(uint key) {
        return *agencies->get(key);
    }

    void AgencyRepository::insertOrUpdate(entities::Agency* newEntity) {
        uint newKey = Utils::hashFunction(newEntity->getId(), agencies->getMaxSize());
        agencies->insert(newKey, newEntity);
    }

    void AgencyRepository::remove(uint key) {
        agencies->remove(key);
    }

    uint AgencyRepository::count() {
        return agencies->getSize();
    }
};