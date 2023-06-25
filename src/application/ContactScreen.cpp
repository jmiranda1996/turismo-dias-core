#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <stdlib.h>
#include "Colors.h"
#include "ContactScreen.h"
#include "../domain/entities/Agency.h"
#include "../domain/entities/ContactForm.h"
#include "../domain/shared/Enums.h"
#include "../infraestructure/repository/AgencyRepository.h"
#include "../infraestructure/repository/ContactFormRepository.h"

using namespace std;
using namespace tdc::domain::entities;
using namespace tdc::domain::shared;
using namespace tdc::infraestructure::repository;

void ContactScreen::displayInfo() {
    drawnContent("Pasajes:", true, ANSI_COLOR_RED);
    drawnContent("Cel: (+51) 966317940", false, ANSI_COLOR_YELLOW);
    drawnContent("Tel: (01) 3981733", false, ANSI_COLOR_YELLOW);
    drawnContent("Email: pasajes@turismodias.com", false, ANSI_COLOR_YELLOW);
};

void ContactScreen::render() {
    
    drawnBorder();
    drawnContent("", false, ANSI_COLOR_RESET);

    drawnContent("1. Ingresar consulta/reclamo", false, ANSI_COLOR_GREEN);
    drawnContent("2. Salir", false, ANSI_COLOR_GREEN);
    drawnContent("", false, ANSI_COLOR_RESET);
    drawnContent("Escoge una opcion:", false, ANSI_COLOR_GREEN);

    drawnContent("", false, ANSI_COLOR_RESET);
    displayInfo();

    drawnContent("", false, ANSI_COLOR_RESET);
    drawnBorder();
};
 
void ContactScreen::load() {
    int option = 0;

    string documentId;
    DocumentType documentType;
    string firstName;
    string lastName;
    string emailAddress;
    string phoneNumber;
    string subject;
    string reason;
    int agencyIndex;

    ContactFormRepository* repository = ContactFormRepository::GetInstance();
    AgencyRepository* agencyRepository = AgencyRepository::GetInstance();
    entities::ContactForm* newContactForm;

    do {
        render();
        cin >> option;
        
        if (option == 1) {
            drawnContent("Tipo de documento (1.DNI, 2.CARNET DE EXTRANJERIA, 3. RUC):", false, ANSI_COLOR_GREEN);
            int _documentType;
            cin >> _documentType;
            if (_documentType == 1) documentType = DNI;
            else if (_documentType == 2) documentType = CarnetExtranjeria;
            else if (_documentType == 3) documentType = RUC;
            drawnContent("Numero de documento:", false, ANSI_COLOR_GREEN);
            cin >> documentId;
            drawnContent("Nombres:", false, ANSI_COLOR_GREEN);
            getline(cin >> ws, firstName);
            drawnContent("Apellidos:", false, ANSI_COLOR_GREEN);
            getline(cin >> ws, lastName);
            drawnContent("Correo:", false, ANSI_COLOR_GREEN);
            cin >> emailAddress;
            drawnContent("Telefono:", false, ANSI_COLOR_GREEN);
            cin >> phoneNumber;
            drawnContent("Asunto:", false, ANSI_COLOR_GREEN);
            getline(cin >> ws, subject);
            drawnContent("Detalle:", false, ANSI_COLOR_GREEN);
            getline(cin >> ws, reason);

            drawnContent("Escoge una agencia:", false, ANSI_COLOR_GREEN);
            LinkedList<Agency> agencies = agencyRepository->getAll();
            for (int i = 0; i < agencies.getLength(); i++)
            {
                string prompt = "(" + to_string(i+1) + "." + agencies.elementAt(i).getTerminalName() + ")";
                cout << ANSI_COLOR_GREEN << prompt << ANSI_COLOR_RESET;
            }
            cin >> agencyIndex;

            Agency* agency = new Agency();
            Agency _agency = agencies.elementAt(agencyIndex);
            agency->setAddress(_agency.getAddress());
            agency->setCity(_agency.getCity());
            agency->setCountry(_agency.getCountry());
            agency->setId(_agency.getId());
            agency->setPhoneNumber(_agency.getPhoneNumber());
            agency->setTerminalName(_agency.getTerminalName());
            agency->setZipCode(_agency.getZipCode());
            newContactForm = new entities::ContactForm(
                documentId, documentType, firstName, lastName, emailAddress, phoneNumber, subject, reason, agency);
            repository->insertOrUpdate(newContactForm);
            
            // *************
            // comentario para probar que todo se lista bien
            // LinkedList<entities::ContactForm> a = repository->getAll();
            // for (int i = 0; i < a.getLength(); i++)
            // {
            //     cout << a.elementAt(i).getDocumentId() << endl;
            // }

            drawnContent("", false, ANSI_COLOR_YELLOW);
            drawnContent("Tu consulta/reclamo se envio con exito", true, ANSI_COLOR_YELLOW);

            option = 0;
        }

    } while (option != 2);
};

 