#ifndef ContactFormRepository_H
#define ContactFormRepository_H

#include <iostream>
#include "../structures/HashTable.h"
#include "../structures/LinkedList.h"
#include "../../domain/interfaces/GenericInterface.h"
#include "../../domain/entities/ContactForm.h"
 
using namespace std;
using namespace tdc::domain;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    class ContactFormRepository {
        private:
            HashTable<entities::ContactForm>* contactForms;
        protected:
            ContactFormRepository() {
                contactForms = new structures::HashTable<entities::ContactForm>(50000);
            }
            static ContactFormRepository* singleton;
        public:
            ContactFormRepository(ContactFormRepository &other) = delete;
            void operator=(const ContactFormRepository &) = delete;
            static ContactFormRepository *GetInstance();

            LinkedList<entities::ContactForm> getAll();
            entities::ContactForm get(uint key);
            void insertOrUpdate(entities::ContactForm* newEntity);
            void remove(uint key);
            uint count();
    };
};

#endif