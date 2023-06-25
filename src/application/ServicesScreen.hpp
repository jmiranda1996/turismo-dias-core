#include <iostream>
#include <stdlib.h>
#include <string>
#include "Colors.h"

using namespace std;

class ServicesScreen {
    public:  
        static void load() {
        cout << ANSI_COLOR_RED;
        cout << ANSI_STYLE_BOLD;
        cout << endl;
        cout << "Nuesros Servicios" << endl;
        cout << endl;
        cout << "\t============ BUS CAMA =============" << endl;
        cout << ANSI_COLOR_RESET;
        cout << ANSI_COLOR_YELLOW;
        cout << "\tTe ofrecemos un servicio directo, cómodo y seguro a un precio accesible para que no dejes de viajar." << endl;
        cout << "\t* Bus climatizado" << endl;
        cout << "\t* Baño quimico" << endl;
        cout << "\t* Monitoreado por GPS" << endl;
        cout << endl;
        cout << endl;
        cout << ANSI_COLOR_RESET;
        cout << ANSI_COLOR_RED;
        cout << ANSI_STYLE_BOLD;
        cout << "\t============ BUS ECONOMICO =============" << endl;
        cout << ANSI_COLOR_RESET;
        cout << ANSI_COLOR_YELLOW;
        cout << "\tEn nuestro servicio encontrarás puertos usb para mantenerte conectado en todo momento así como asientos" << endl;
        cout << "\tergonómicos cama de 150° que te garantizarán el mejor descanso " << endl;
        cout << "\t* Asientos 150°" << endl;
        cout << "\t* Bus climatizado" << endl;
        cout << "\t* Baño quimico" << endl;
        cout << "\t* Monitoreado por GPS" << endl;
        cout << endl;
        cout << endl;
        cout << ANSI_COLOR_RESET;
    }
};