#include <iostream>
#include "ContactForm.h"
// #include "Agency.h"
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    ContactForm::ContactForm() {
        documentId = "";
        documentType = DNI;
        firstName = "";
        lastName = "";
        emailAddress = "";
        phoneNumber = "";
        subject = "";
        reason = "";
        agency = nullptr;
    };
    ContactForm::ContactForm(
        string _documentId,
        DocumentType _documentType,
        string _firstName,
        string _lastName,
        string _emailAddress,
        string _phoneNumber,
        string _subject,
        string _reason,
        Agency* _agency
    ) {
        documentId = _documentId;
        documentType = _documentType;
        firstName = _firstName;
        lastName = _lastName;
        emailAddress = _emailAddress;
        phoneNumber = _phoneNumber;
        subject = _subject;
        reason = _reason;
        agency = _agency;
    }

    string ContactForm::getId() { return id; };
    string ContactForm::getDocumentId() { return documentId; };
    DocumentType ContactForm::getDocumentType() { return documentType; };
    string ContactForm::getFirstName() { return firstName; };
    string ContactForm::getLastName() { return lastName; };
    string ContactForm::getEmailAddress() { return emailAddress; };
    string ContactForm::getPhoneNumber() { return phoneNumber; };
    string ContactForm::getSubject() { return subject; };
    string ContactForm::getReason() { return reason; };
    Agency* ContactForm::getAgency() { return agency; };

    void ContactForm::setId(string _id) { id = _id; }
    void ContactForm::setDocumentId(string _documentId) { documentId = _documentId; };
    void ContactForm::setDocumentType(DocumentType _documentType) { _documentType = documentType; };
    void ContactForm::setFirstName(string _firstName) { firstName = _firstName; };
    void ContactForm::setLastName(string _lastName) { lastName = _lastName; };
    void ContactForm::setEmailAddress(string _emailAddress) { emailAddress = _emailAddress; };
    void ContactForm::setPhoneNumber(string _phoneNumber) { phoneNumber = _phoneNumber; };
    void ContactForm::setSubject(string _subject) { subject = _subject; };
    void ContactForm::setReason(string _reason) { reason = _reason; };
    void ContactForm::setAgency(Agency* _agency) { agency = _agency; };
}