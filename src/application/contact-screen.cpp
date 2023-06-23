#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <stdlib.h>
#include "contact-screen.h"
#include "../domain/entities/ContactForm.h"
#include "../domain/shared/Enums.h"
#include "../infraestructure/repository/ContactFormRepository.h"

using namespace std;
using namespace tdc::domain;
using namespace tdc::domain::shared;
using namespace tdc::infraestructure::repository;

const string ANSI_COLOR_YELLOW = "\x1b[33m";
const string ANSI_STYLE_BOLD = "\x1b[1m";
const string ANSI_COLOR_RESET = "\x1b[0m";
const string ANSI_COLOR_BLUE = "\x1b[34m";
const string ANSI_COLOR_RED = "\x1b[31m";

void ContactScreen::drawnBorder() {
    cout << setfill( '*' ) << setw(screenWidth) << '*' <<  endl;
};

void ContactScreen::drawnContent(string content, bool bold = false, string color = ANSI_COLOR_RESET) {
    cout << "* " << left << setfill(' ');
    cout << color;
    if (bold) cout << ANSI_STYLE_BOLD;
    cout << setw(screenWidth - 4) << content;
    cout << ANSI_COLOR_RESET;
    cout << '*' << endl;
};

void ContactScreen::displayInfo() {
    drawnContent("Pasajes:", true, ANSI_COLOR_RED);
    drawnContent("Cel: (+51) 966317940", false, ANSI_COLOR_YELLOW);
    drawnContent("Tel: (01) 3981733", false, ANSI_COLOR_YELLOW);
    drawnContent("Email: pasajes@turismodias.com", false, ANSI_COLOR_YELLOW);
};

void ContactScreen::render() {
    
    drawnBorder();
    drawnContent(" ");

    drawnContent("1. Ingresar consulta/reclamo", false, ANSI_COLOR_YELLOW);
    drawnContent("2. Salir", false, ANSI_COLOR_YELLOW);
    drawnContent(" ");
    drawnContent("Ingresa una opcion:", false, ANSI_COLOR_YELLOW);

    drawnContent(" ");
    displayInfo();

    drawnContent(" ");
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

    ContactFormRepository* repository = ContactFormRepository::GetInstance();
    entities::ContactForm* newContactForm;

    do {
        render();
        cin >> option;
        
        if (option == 1) {
            
            // Agency* agency;
            drawnContent("Tipo de documento (1.DNI, 2.CARNET DE EXTRANJERIA, 3. RUC):", false, ANSI_COLOR_BLUE);
            int _documentType;
            cin >> _documentType;
            if (_documentType == 1) documentType = DNI;
            else if (_documentType == 2) documentType = CarnetExtranjeria;
            else if (_documentType == 3) documentType = RUC;
            drawnContent("Numero de documento:", false, ANSI_COLOR_BLUE);
            cin >> documentId;
            drawnContent("Nombres:", false, ANSI_COLOR_BLUE);
            cin >> firstName;
            drawnContent("Apellidos:", false, ANSI_COLOR_BLUE);
            cin >> lastName;
            drawnContent("Correo:", false, ANSI_COLOR_BLUE);
            cin >> emailAddress;
            drawnContent("Telefono:", false, ANSI_COLOR_BLUE);
            cin >> phoneNumber;
            drawnContent("Asunto:", false, ANSI_COLOR_BLUE);
            cin >> subject;
            drawnContent("Detalle:", false, ANSI_COLOR_BLUE);
            cin >> reason;

            newContactForm = new entities::ContactForm(
                documentId, documentType, firstName, lastName, emailAddress, phoneNumber, subject, reason, nullptr);
            repository->insertOrUpdate(newContactForm);
            
            // *************
            // comentario para probar que todo se lista bien
            // LinkedList<entities::ContactForm> a = repository->getAll();
            // for (int i = 0; i < a.getLength(); i++)
            // {
            //     cout << a.elementAt(i).getDocumentId() << endl;
            // }

            drawnContent("");
            drawnContent("Tu consulta/reclamo se envio con exito", true, ANSI_COLOR_YELLOW);

            option = 0;
        }

    } while (option != 2);
};

 