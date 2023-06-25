#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <stdlib.h>
#include "Colors.h"
#include "Global.h"
#include "ReportsScreen.h"
#include "../domain/entities/Booking.h"
#include "../domain/entities/Schedule.h"
#include "../domain/entities/Client.h"
#include "../domain/entities/Driver.h"
#include "../domain/entities/Bus.h"
#include "../domain/entities/ContactForm.h"
#include "../domain/shared/Enums.h"
#include "../infraestructure/repository/BookingRepository.h"
#include "../infraestructure/repository/ScheduleRepository.h"
#include "../infraestructure/repository/ClientRepository.h"
#include "../infraestructure/repository/DriverRepository.h"
#include "../infraestructure/repository/BusRepository.h"
#include "../infraestructure/repository/ContactFormRepository.h"
#include "../infraestructure/structures/LinkedList.h"
#include "../infraestructure/common/Utils.h"

using namespace std;
using namespace tdc::domain::entities;
using namespace tdc::infraestructure::repository;

void ReportsScreen::render() {
    
    drawnBorder();
    drawnContent("", false, ANSI_COLOR_RESET);

    drawnContent("============ REPORTES =============", false, ANSI_COLOR_PURPLE);
    drawnContent("", false, ANSI_COLOR_GREEN);
    drawnContent("1. Lista de reservas", false, ANSI_COLOR_GREEN);
    drawnContent("2. Lista de programaciones", false, ANSI_COLOR_GREEN);
    drawnContent("3. Lista de clientes", false, ANSI_COLOR_GREEN);
    drawnContent("4. Lista de choferes", false, ANSI_COLOR_GREEN);
    drawnContent("5. Lista de buses", false, ANSI_COLOR_GREEN);
    drawnContent("6. Lista de formulario de contacto", false, ANSI_COLOR_GREEN);
    drawnContent("7. Salir", false, ANSI_COLOR_GREEN);
    drawnContent("", false, ANSI_COLOR_GREEN);
    drawnContent("Escoge una opcion:", false, ANSI_COLOR_GREEN);

    drawnContent("", false, ANSI_COLOR_RESET);
    drawnBorder();
};
 
void ReportsScreen::load() {
    int option = 0;

    if (!Global::isLogin || Global::admin == nullptr) {
        drawnContent("Debe iniciar sesion como administrador para ver los reportes", true, ANSI_COLOR_RED);
        // return;
    }

    BookingRepository* bookingRepository = BookingRepository::GetInstance();
    ScheduleRepository* schedulesRepository = ScheduleRepository::GetInstance();
    ClientRepository* clientRepository = ClientRepository::GetInstance();
    DriverRepository* driverRepository = DriverRepository::GetInstance();
    BusRepository* busRepository = BusRepository::GetInstance();
    ContactFormRepository* contactFormRepository = ContactFormRepository::GetInstance();

    LinkedList<Booking> bookings = bookingRepository->getAll();
    LinkedList<Schedule> schedules = schedulesRepository->getAll();
    LinkedList<Client> clients = clientRepository->getAll();
    LinkedList<entities::Driver> drivers = driverRepository->getAll();
    LinkedList<Bus> buses = busRepository->getAll();
    LinkedList<ContactForm> contactForms = contactFormRepository->getAll();

    do {
        render();
        cin >> option;
        
        switch (option)
        {
            case 1:
                drawnContent("", false, ANSI_COLOR_YELLOW);
                drawnContent("Nro\tId\tClient\tOrigen\tDestino\tSalida\tPrecio", false, ANSI_COLOR_GREEN);
                drawnContent("___\t______\t_______\t______\t______", false, ANSI_COLOR_GREEN);
                for (int i = 0; i < bookings.getLength(); i++)
                {
                    Booking booking = bookings.elementAt(i);
                    string line = to_string(i) + "\t";
                    line += booking.getId() + "\t";
                    line += booking.getClient()->getDocumentId() + " - " + booking.getClient()->getUsername() + "\t";
                    line += booking.getSchedule()->getFrom() + "\t";
                    line += booking.getSchedule()->getTo() + "\t";
                    line += Utils::timeToString(booking.getSchedule()->getDepartureDate()) + "\t";
                    line += to_string(booking.getBookingPayInfo()->getTotal());
                    drawnContent(line, false, ANSI_COLOR_GREEN);
                }
                drawnContent("", false, ANSI_COLOR_YELLOW);
                break;
            case 2:
                drawnContent("", false, ANSI_COLOR_YELLOW);
                drawnContent("Nro\tId\tOrigen\tDestino\tSalida\tPrecio", false, ANSI_COLOR_GREEN);
                drawnContent("___\t______\t_______\t______\t______", false, ANSI_COLOR_GREEN);
                for (int i = 0; i < schedules.getLength(); i++)
                {
                    Schedule schedule = schedules.elementAt(i);
                    string line = to_string(i) + "\t";
                    line += schedule.getId() + "\t";
                    line += schedule.getFrom() + "\t";
                    line += schedule.getTo() + "\t";
                    line += Utils::timeToString(schedule.getDepartureDate()) + "\t";
                    line += to_string(schedule.getPrice());
                    drawnContent(line, false, ANSI_COLOR_GREEN);
                }
                drawnContent("", false, ANSI_COLOR_YELLOW);
                break;
            case 3:
                drawnContent("", false, ANSI_COLOR_YELLOW);
                drawnContent("Nro\tNro Documento\tUsername\tCorreo\tPuntos\tStatus", false, ANSI_COLOR_GREEN);
                drawnContent("___\t______\t_______\t______\t______", false, ANSI_COLOR_GREEN);
                for (int i = 0; i < clients.getLength(); i++)
                {
                    Client client = clients.elementAt(i);
                    string line = to_string(i) + "\t";
                    line += client.getDocumentId() + "\t";
                    line += client.getUsername() + "\t";
                    line += client.getEmailAddress() + "\t";
                    line += to_string(client.getPoints()) + "\t";
                    line += client.getStatus() == 0 ? "A" : "I";
                    drawnContent(line, false, ANSI_COLOR_GREEN);
                }
                drawnContent("", false, ANSI_COLOR_YELLOW);
                break;
            case 4:
                drawnContent("", false, ANSI_COLOR_YELLOW);
                drawnContent("Nro\tNro Documento\tNombre\tNro de Licencia\tCorreo\tStatus", false, ANSI_COLOR_GREEN);
                drawnContent("___\t______\t_______\t______\t______", false, ANSI_COLOR_GREEN);
                for (int i = 0; i < drivers.getLength(); i++)
                {
                    entities::Driver driver = drivers.elementAt(i);
                    string line = to_string(i) + "\t";
                    line += driver.getDocumentId() + "\t";
                    line += driver.getUsername() + "\t";
                    line += driver.getDriverInfo()->getDriverLicense() + "\t";
                    line += driver.getEmailAddress() + "\t";
                    line += driver.getStatus() == 0 ? "A" : "I";
                    drawnContent(line, false, ANSI_COLOR_GREEN);
                }
                drawnContent("", false, ANSI_COLOR_YELLOW);
                break;
            case 5:
                drawnContent("", false, ANSI_COLOR_YELLOW);
                drawnContent("Nro\tId\tNro Documento\tNro de asientos\tTipo de servicio", false, ANSI_COLOR_GREEN);
                drawnContent("___\t______\t_______\t______\t______", false, ANSI_COLOR_GREEN);
                for (int i = 0; i < buses.getLength(); i++)
                {
                    Bus bus = buses.elementAt(i);
                    string line = to_string(i) + "\t";
                    line += bus.getId() + "\t";
                    line += bus.getDriver()->getUsername() + "\t";
                    line += to_string(bus.getSeats()) + "\t";
                    switch (bus.getServiceType())
                    {
                        case 0: line += "Express\t"; break;
                        case 1: line += "Cruzero\t"; break;
                        case 2: line += "Premiun\t"; break;
                        default: break;
                    }
                    drawnContent(line, false, ANSI_COLOR_GREEN);
                }
                drawnContent("", false, ANSI_COLOR_YELLOW);
                break;
            case 6:
                drawnContent("", false, ANSI_COLOR_YELLOW);
                drawnContent("Nro\tNro Documento\tNombre\tApellido\tCorreo\tTelefono\tAsunto\tDetalle\tAgencia", false, ANSI_COLOR_GREEN);
                drawnContent("___\t_____________\t_______\t_______\t______\t________\t______\t_______\t_______", false, ANSI_COLOR_GREEN);
                for (int i = 0; i < contactForms.getLength(); i++)
                {
                    ContactForm contactForm = contactForms.elementAt(i);
                    string line = to_string(i) + "\t";
                    line += contactForm.getDocumentId() + "\t";
                    line += contactForm.getFirstName() + "\t";
                    line += contactForm.getLastName() + "\t";
                    line += contactForm.getEmailAddress() + "\t";
                    line += contactForm.getPhoneNumber() + "\t";
                    line += contactForm.getSubject() + "\t";
                    line += contactForm.getReason() + "\t";
                    line += contactForm.getAgency()->getTerminalName();
                    drawnContent(line, false, ANSI_COLOR_GREEN);
                }
                drawnContent("", false, ANSI_COLOR_YELLOW);
                break;
            default:
                cout << "Esa opcion no es valida" << endl;
                break;
        }

    } while (option != 7);
};