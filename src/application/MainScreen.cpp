#include <iostream>
#include <stdlib.h>
#include <string>
#include "Colors.h"
#include "MainScreen.h"
#include "BookingScreen.h"

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
        
        system("clear");
        switch (option)
        {
            case 1:
                BookingScreen::load();
                break;
            case 2:
                // MainScreen::Mostrar_menu();
                break;
            case 3:
                // MainScreen::Mostrar_menu();
            default:
                cout << "Esa opcion no es valida" << endl;
                break;
        }
    } while (option != 7);
};