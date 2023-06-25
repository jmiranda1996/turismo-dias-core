#include <iostream>
#include <stdlib.h>
#include <string>
#include "Colors.h"
#include "MainScreen.h"
#include "BookingScreen.h"
#include "ServicesScreen.hpp"
#include "ContactScreen.h"
#include "ProfileScreen.h"
#include "BookingsHistoryScreen.h"
#include "ReportsScreen.h"

using namespace std;

void MainScreen::render() {
    drawnBorder();

    drawnContent("", false, ANSI_COLOR_GREEN);
    drawnContent("============ MENU PRINCIPAL =============", false, ANSI_COLOR_PURPLE);
    drawnContent("", false, ANSI_COLOR_GREEN);
    drawnContent("1. Realizar reserva", false, ANSI_COLOR_GREEN);
    drawnContent("2. Ver servicios", false, ANSI_COLOR_GREEN);
    drawnContent("3. Contactenos", false, ANSI_COLOR_GREEN);
    drawnContent("4. Perfil", false, ANSI_COLOR_GREEN);
    drawnContent("5. Historial de reservas", false, ANSI_COLOR_GREEN);
    drawnContent("6. Reportes", false, ANSI_COLOR_GREEN);
    drawnContent("7. Salir", false, ANSI_COLOR_GREEN);
    drawnContent("", false, ANSI_COLOR_GREEN);
    drawnContent("Escoge una opcion:", false, ANSI_COLOR_GREEN);

    drawnContent(" ", false, ANSI_COLOR_GREEN);
    drawnBorder();
};
 
void MainScreen::load() {
    int option = 0;
    do {
        render();
        cin >> option;
        
        switch (option)
        {
            case 1:
                BookingScreen::load();
                break;
            case 2:
                ServicesScreen::load();
                break;
            case 3:
                ContactScreen::load();
                break;
            case 4:
                ProfileScreen::load();
                break;
            case 5:
                BookingsHistoryScreen::load();
                break;
            case 6:
                ReportsScreen::load();
                break;
            default:
                cout << "Esa opcion no es valida" << endl;
                break;
        }
    } while (option != 7);
};