#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <cstring>
#include "Colors.h"
#include "BookingScreen.h"
#include "../domain/entities/Booking.h"
#include "../domain/entities/BookingPayInfo.h"
#include "../domain/entities/Schedule.h"
#include "../infraestructure/repository/BookingRepository.h"
#include "../infraestructure/repository/ScheduleRepository.h"
#include "../infraestructure/structures/LinkedList.h"
#include "../infraestructure/common/Utils.h"

using namespace std;
using namespace tdc::domain::entities;
using namespace tdc::infraestructure::repository;
using namespace tdc::infraestructure::structures;

void BookingScreen::render() {
    drawnBorder();
    
    drawnContent("", false, ANSI_COLOR_GREEN);

    string prompt;
    int from = 0;
    int to = 0;
    string departureDate = "";
    string returnDate = "";
    int scheduleIndex = 0;
    int passengersQuantity = 0;
    vector<uint8_t> seats;
    int paidMethod = 0;
    int total = 0;

    prompt = "Ingrese Origen (1.Lima) (2.Arequipa) (3.Piura) (4.Ica) (5.Cusco) (6.Cajamarca) (7.Huancayo) (8.Chiclayo) (9.Pisco):";
    drawnContent(prompt, false, ANSI_COLOR_GREEN);
    cin >> from;

    prompt = "Ingrese Destino (1.Lima) (2.Arequipa) (3.Piura) (4.Ica) (5.Cusco) (6.Cajamarca) (7.Huancayo) (8.Chiclayo) (9.Pisco):";
    drawnContent(prompt, false, ANSI_COLOR_GREEN);
    cin >> to;

    prompt = "Ingrese fecha de salida (dd-mm-yyyy):";
    drawnContent(prompt, false, ANSI_COLOR_GREEN);
    cin >> departureDate;
    // strftime ( str, sizeof(str), "%A", timeinfo );

    prompt = "Ingrese fecha de retorno (dd-mm-yyyy) - opcional (-):";
    drawnContent(prompt, false, ANSI_COLOR_GREEN);
    getline(cin >> ws, returnDate);

    drawnContent("Resultado de busqueda:", true, ANSI_COLOR_YELLOW);
    drawnContent("", false, ANSI_COLOR_YELLOW);
    drawnContent("Nro\tOrigen\tDestino\tSalida\tPrecio", false, ANSI_COLOR_GREEN);
    drawnContent("___\t______\t_______\t______\t______", false, ANSI_COLOR_GREEN);
    ScheduleRepository* _scheduleRepository = ScheduleRepository::GetInstance();
    LinkedList<Schedule> schedules = _scheduleRepository->getAll();
    auto castToOrFrom = [](int option) -> string {
        string result = "";
        switch(option) {
            case 1: result = "Lima"; break;
            case 2: result = "Arequipa";  break;
            case 3: result = "Piura";  break;
            case 4: result = "Ica";  break;
            case 5: result = "Cusco";  break;
            case 6: result = "Cajamarca";  break;
            case 7: result = "Huancayo";  break;
            case 8: result = "Chiclayo";  break;
            case 9: result = "Pisco";  break;
            default: break;
        }
        return result;
    };
    for (int i = 0; i < schedules.getLength(); i++)
    {
        Schedule schedule = schedules.elementAt(i);
        if(schedule.getFrom() == castToOrFrom(from) && schedule.getTo() == castToOrFrom(to)) {
            string line = to_string(i) + "\t";
            line += schedule.getFrom() + "\t";
            line += schedule.getTo() + "\t";
            line += Utils::timeToString(schedule.getDepartureDate()) + "\t";
            line += to_string(schedule.getPrice());
            drawnContent(line, false, ANSI_COLOR_GREEN);
        }
    }
    
    drawnContent("", false, ANSI_COLOR_GREEN);
    drawnContent("Escoge una opcion:", false, ANSI_COLOR_GREEN);
    cin >> scheduleIndex;

    prompt = "Ingrese cantidad de pasajeros:";
    drawnContent(prompt, false, ANSI_COLOR_GREEN);
    cin >> passengersQuantity;

    for (int i = 0; i < passengersQuantity; i++)
    {
        int seat = 0;
        prompt = "Ingrese asiento (1-30) para el pasajero " + to_string(i + 1) + ":";
        drawnContent(prompt, false, ANSI_COLOR_GREEN);
        cin >> seat;

        string dni = "";
        prompt = "Ingresa DNI del pasajero " + to_string(i + 1) + ":";
        drawnContent(prompt, false, ANSI_COLOR_GREEN);
        cin >> dni;

        string nombres = "";
        prompt = "Ingresa nombres del pasajero " + to_string(i + 1) + ":";
        drawnContent(prompt, false, ANSI_COLOR_GREEN);
        getline(cin >> ws, nombres);

        seats.push_back(seat);
    }
    
    total = schedules.elementAt(scheduleIndex).getPrice() * passengersQuantity;
    prompt = "El total es " + to_string(total);
    drawnContent(prompt, false, ANSI_COLOR_YELLOW);

    prompt = "Escoge metodo de pago (1.CREDITO) (2.YAPE) (3.PAYPAL) (4.TRANSFERENCIA):";
    drawnContent(prompt, false, ANSI_COLOR_GREEN);
    cin >> paidMethod;

    Booking* newBooking = new Booking();
    newBooking->setId(Utils::generateGUUID());
    newBooking->setClient(nullptr);
    Schedule newSchedule = schedules.elementAt(scheduleIndex);
    newBooking->setSchedule(&newSchedule);
    newBooking->setPassengers(passengersQuantity);
    newBooking->setSeats(seats);
    newBooking->setBookingDate(time(0));
    newBooking->setBookingPayInfo(new BookingPayInfo(
        total, total - (total * 0.18), total * 0.18, time(0), 0
    ));
    BookingRepository* repository = BookingRepository::GetInstance();
    repository->insertOrUpdate(newBooking);

    prompt = "¡Reserva realizada con exito!";
    drawnContent(prompt, true, ANSI_COLOR_YELLOW);

    drawnContent(" ", false, ANSI_COLOR_GREEN);
    drawnBorder();
};
 
void BookingScreen::load() {
    render();
};