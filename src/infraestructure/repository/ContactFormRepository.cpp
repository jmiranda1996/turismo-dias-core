#include <iostream>
#include "ContactFormRepository.h"
#include "../structures/HashTable.h"
#include "../structures/LinkedList.h"
#include "../common/Utils.h"
#include "../../domain/entities/ContactForm.h"
 
using namespace std;
using namespace tdc::domain;
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
        for (int i = 0; i < maxSize; i++)
        {
            entities::ContactForm* contactForm = contactForms->get(i);
            if (contactForm != nullptr)
                list.insert(*contactForm);
        }
        return list;
    }

    entities::ContactForm ContactFormRepository::get(int key) {
        return *contactForms->get(key);
    }

    void ContactFormRepository::insertOrUpdate(entities::ContactForm* newEntity) {
        int newKey = Utils::hashFunction(newEntity->getDocumentId(), contactForms->getMaxSize());
        contactForms->insert(newKey, newEntity);
    }

    void ContactFormRepository::remove(int key) {
        contactForms->remove(key);
    }

    int ContactFormRepository::count() {
        return contactForms->getSize();
    }
};