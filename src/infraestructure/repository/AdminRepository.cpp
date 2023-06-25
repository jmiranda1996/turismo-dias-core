#include <iostream>
#include "AdminRepository.h"
#include "../structures/HashTable.h"
#include "../structures/LinkedList.h"
#include "../common/Utils.h"
#include "../../domain/entities/Admin.h"
 
using namespace std;
using namespace tdc::domain;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    AdminRepository* AdminRepository::singleton= nullptr;
    
    AdminRepository* AdminRepository::GetInstance() {
        if(singleton == nullptr){
            singleton = new AdminRepository();
        }
        return singleton;
    }

    LinkedList<entities::Admin> AdminRepository::getAll() {
        int maxSize = admins->getMaxSize();
        LinkedList<entities::Admin> list;
        for (int i = 0; i < maxSize; i++)
        {
            entities::Admin* admin = admins->get(i);
            if (admin != nullptr)
                list.insert(*admin);
        }
        return list;
    }

    entities::Admin AdminRepository::get(int key) {
        return *admins->get(key);
    }

    void AdminRepository::insertOrUpdate(entities::Admin* newEntity) {
        int newKey = Utils::hashFunction(newEntity->getDocumentId(), admins->getMaxSize());
        admins->insert(newKey, newEntity);
    }

    void AdminRepository::remove(int key) {
        admins->remove(key);
    }

    int AdminRepository::count() {
        return admins->getSize();
    }
};