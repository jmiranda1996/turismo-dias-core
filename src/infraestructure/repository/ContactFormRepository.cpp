#include <iostream>
#include "ContactFormRepository.h"
#include "../structures/HashTable.h"
#include "../structures/LinkedList.h"
#include "../common/Utils.h"
#include "../../domain/entities/ContactForm.h"
 
using namespace std;
using namespace tdc::domain::shared;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    ContactFormRepository* ContactFormRepository::singleton= nullptr;
    
    ContactFormRepository* ContactFormRepository::GetInstance() {
        if(singleton == nullptr){
            singleton = new ContactFormRepository();
        }
        return singleton;
    }

    LinkedList<entities::ContactForm> ContactFormRepository::getAll() {
        int maxSize = contactForms->getMaxSize();
        LinkedList<entities::ContactForm> list;
        for (uint i = 0; i < maxSize; i++)
        {
            entities::ContactForm* contactForm = contactForms->get(i);
            if (contactForm != nullptr)
                list.insert(*contactForm);
        }
        return list;
    }

    entities::ContactForm ContactFormRepository::get(uint key) {
        return *contactForms->get(key);
    }

    void ContactFormRepository::insertOrUpdate(entities::ContactForm* newEntity) {
        uint newKey = Utils::hashFunction(newEntity->getDocumentId(), contactForms->getMaxSize());
        contactForms->insert(newKey, newEntity);
    }

    void ContactFormRepository::remove(uint key) {
        contactForms->remove(key);
    }

    uint ContactFormRepository::count() {
        return contactForms->getSize();
    }
};