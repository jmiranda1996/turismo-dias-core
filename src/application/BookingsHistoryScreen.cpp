#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <cstring>
#include "Colors.h"
#include "Global.h"
#include "BookingsHistoryScreen.h"
#include "../domain/entities/Booking.h"
#include "../infraestructure/common/Utils.h"
#include "../infraestructure/repository/BookingRepository.h"
#include "../infraestructure/structures/LinkedList.h"

using namespace std;
using namespace tdc::domain::entities;
using namespace tdc::infraestructure::repository;

void BookingsHistoryScreen::render() {
    drawnBorder();
    drawnContent("", false, ANSI_COLOR_GREEN);

    drawnContent("============ Historial de reservas =============", false, ANSI_COLOR_PURPLE);
    drawnContent("", false, ANSI_COLOR_GREEN);
    if (!Global::isLogin) {
        drawnContent("Debe iniciar sesion para ver su historial", true, ANSI_COLOR_RED);
        return;
    }

    BookingRepository* repository = BookingRepository::GetInstance();
    LinkedList<Booking> bookings = repository->getAll();

    if (Global::client != nullptr) {
        drawnContent("", false, ANSI_COLOR_YELLOW);
        drawnContent("Nro\tid\tfrom\tto\tSalida\tTotal", false, ANSI_COLOR_GREEN);
        drawnContent("___\t______\t_______\t______\t______", false, ANSI_COLOR_GREEN);
        for (int i = 0; i < bookings.getLength(); i++)
        {
            Booking booking = bookings.elementAt(i);
            if (booking.getClient()->getDocumentId() != Global::client->getDocumentId()) continue;
            string line = to_string(i) + "\t";
            line += booking.getId();
            line += booking.getSchedule()->getFrom() + "\t";
            line += booking.getSchedule()->getTo() + "\t";
            line += Utils::timeToString(booking.getSchedule()->getDepartureDate());
            line += to_string(booking.getBookingPayInfo()->getTotal());
            drawnContent(line, false, ANSI_COLOR_GREEN);
        }
    }
    else {
        drawnContent("No se encontraron reservas", true, ANSI_COLOR_GREEN);
    }

    drawnContent(" ", false, ANSI_COLOR_GREEN);
    drawnBorder();
};
 
void BookingsHistoryScreen::load() {
    render();
};