#include <iostream>
#include <stdlib.h>
#include <string>
#include "Reserva.hpp"
#include "Servicios.hpp"
#include "contact-screen.h"

#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_STYLE_BOLD    "\x1b[1m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_BLUE    "\x1b[34m"

using namespace std;

class MainScreen {
    public:  
    static void Mostrar_menu() {
        int opcion;

        Reserva reservacion;
        do {
            cout << ANSI_COLOR_YELLOW;
            cout << ANSI_STYLE_BOLD;
            cout << "============ MENÚ PRINCIPAL =============" << endl;
            cout << ANSI_COLOR_RESET;
            cout << ANSI_COLOR_BLUE;
            cout << "1. Realizar reserva" << endl;
            cout << "2. Ver servicios" << endl;
            cout << "3. Contáctenos" << endl;
            cout << "4. Perfil" << endl;
            cout << "5. Historial de reservas" << endl;
            cout << "6. Reportes" << endl;
            cout << "7. Salir" << endl;
            cout << "Ingrese una opción: ";
            cin >> opcion;
            system("clear");

            cout << ANSI_COLOR_RESET;
            switch (opcion)
            {
                case 1:
                    reservacion.Reservar();
                    break;
                case 2:
                    Servicios::Mostrar_servicios();
                    break;
                case 3:
                    ContactScreen::load();
                    break;
                case 4:
                case 5:
                case 6:
                    break;
                default:
                    break;
            }
        } while(opcion != 7);

    }
};