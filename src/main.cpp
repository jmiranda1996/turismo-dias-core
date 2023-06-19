#include <iostream>
#include <string>
#include <stdlib.h>
//#include "./domain/entities/Client.h"
//#include "./domain/shared/User.h"
//#include <conio.h>
using namespace std;

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_STYLE_BOLD    "\x1b[1m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void mostrar_logo();
void mostrar_lista_buses_();
void informacion_pasajero();

int opcion, asiento, cantidad;
string origen, destino, salida;
bool disponible = true;

void mostrar_logo() {

}

void informacion_pasajero() {
  for(int i = 1;i < cantidad; i++){
    cout << "Pasajero" << i <<": "<<endl; 
  }
}

int main() {
  //mostrar_logo();
  
  cout << ANSI_COLOR_YELLOW;
  cout << ANSI_STYLE_BOLD;
  cout<<"\t\t\t\t\t\t\t\t RESERVA DE PASAJES \n\n";
  cout << ANSI_COLOR_RESET;
  cout << ANSI_COLOR_GREEN; 
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
  cin.ignore(); 
  return 0;
}