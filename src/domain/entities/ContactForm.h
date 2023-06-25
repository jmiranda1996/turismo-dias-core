#ifndef ContactForm_H
#define ContactForm_H

#include <iostream>
#include "Agency.h"
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    class ContactForm {
        private:
            string id;
            string documentId;
            DocumentType documentType;
            string firstName;
            string lastName;
            string emailAddress;
            string phoneNumber;
            string subject;
            string reason;
            Agency* agency;
        public:
            ContactForm();
            ContactForm(
                string _documentId,
                DocumentType _documentType,
                string _firstName,
                string _lastName,
                string _emailAddress,
                string _phoneNumber,
                string _subject,
                string _reason,
                Agency* _agency = nullptr
            );

            string getId();
            string getDocumentId();
            DocumentType getDocumentType();
            string getFirstName();
            string getLastName();
            string getEmailAddress();
            string getPhoneNumber();
            string getSubject();
            string getReason();
            Agency* getAgency();

            void setId(string _id);
            void setDocumentId(string _documentId);
            void setDocumentType(DocumentType _documentType);
            void setFirstName(string _firstName);
            void setLastName(string _lastName);
            void setEmailAddress(string _emailAddress);
            void setPhoneNumber(string _phoneNumber);
            void setSubject(string _subject);
            void setReason(string _reason);
            void setAgency(Agency* _agency);
    };
};

#endif