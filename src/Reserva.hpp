#include <iostream>
#include <stdlib.h>
#include <string>
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_STYLE_BOLD    "\x1b[1m"
#define ANSI_COLOR_RESET   "\x1b[0m"
using namespace std;

class Reserva {
    public:  
    //mostrar_logo();
    
  void Reservar (){
    cout << ANSI_COLOR_YELLOW;
    cout << ANSI_STYLE_BOLD;
    cout << "\t\t\t\t\t\t\t\t RESERVA DE PASAJES \n\n";
    cout << ANSI_COLOR_RESET;
    cout << "*  ORIGEN: ";
    cin >> origen;
    cout << "*  DESTINO: ";
    cin >> destino;
    cout << "*  FECHA DE SALIDA (DD/MM/AAAA): ";
    cin >> salida;
    system("clear");
    cout << ANSI_COLOR_RESET;
  
    cout << ANSI_COLOR_BLUE;
  if(disponible == true){
    cout << "        TIPO    " << " HORA SALIDA   " << "  HORA LLEGADA    " << "  TIEMPO    " << "   COSTO    "<<endl;
    cout << " 1. "<<endl;
    cout << " 2. " <<endl;
    cout << "Opcion: ";
    cin >> opcion;
  }
  cout << ANSI_COLOR_RESET;

  cout << ANSI_COLOR_MAGENTA;
  switch(opcion){
    case 1:
    cout << "\t\t\t\t\t\t\t\tASIENTOS DISPONIBLES " << endl;
    cout << "\nPrimer piso" << endl;
    cout << " 1 - 13 - 14" << endl;
    cout << "\nSegundo piso" << endl;
    cout << " 20 - 33 - 34"<<endl;
    cout << "Asientos escogidos: ";
    cin >> asiento;
    break;
    case 2:
    cout << "\t\t\t\t\t\t\t\tASIENTOS DISPONIBLES " << endl;
    cout << "\nPrimer piso" << endl;
    cout << " 1 - 13 - 14" << endl;
    cout << "\nSegundo piso" << endl;
    cout << " 20 - 33 - 34"<<endl;
    cout << "\nAsientos escogidos: ";
    cin >> asiento;
    break;
    default: 
    break;
  }
  
    cin.ignore(); return 0;
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