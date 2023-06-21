#include <iostream>
#include <stdlib.h>
#include <string>
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_STYLE_BOLD    "\x1b[1m"
#define ANSI_COLOR_RESET   "\x1b[0m"
using namespace std;

class menuPrincipal {
    public:  
    void Mostrar_menu(){
        int opcion;
        do{
            cout << ANSI_COLOR_YELLOW;
            cout << ANSI_STYLE_BOLD;
            cout << "======= MENÚ PRINCIPAL ========" << endl;
            cout << ANSI_COLOR_RESET;
            cout << "1. Realizar reserva" << endl;
            cout << "2. Ver servicios" << endl;
            cout << "3. Contáctenos" << endl;
            cout << "4. Perfil" << endl;
            cout << "5. Salir" << endl;
            cout << "Ingrese una opción: ";
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                break;
            }
        } while (opcion!=5);

    }

};