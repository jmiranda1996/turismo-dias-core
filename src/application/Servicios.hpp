#include <iostream>
#include <stdlib.h>
#include <string>
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_STYLE_BOLD    "\x1b[1m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_BLUE    "\x1b[34m"

#define ANSI_COLOR_RED     "\x1b[31m"
using namespace std;

class Servicios {
    public:  
    static void Mostrar_servicios() {

            cout << ANSI_COLOR_RED;
            cout << ANSI_STYLE_BOLD;
            cout << endl;
            cout << "\t\t============ BUS CAMA =============" << endl;
            cout << ANSI_COLOR_RESET;
            cout << ANSI_COLOR_YELLOW;
            cout << "\t\tTe ofrecemos un servicio directo, cómodo y seguro a un precio accesible para que no dejes de viajar." << endl;
            cout << "\t\t* Bus climatizado" << endl;
            cout << "\t\t* Baño quimico" << endl;
            cout << "\t\t* Monitoreado por GPS" << endl;
            cout << endl;
            cout << endl;
            cout << ANSI_COLOR_RESET;
            cout << ANSI_COLOR_RED;
            cout << ANSI_STYLE_BOLD;
            cout << "\t\t============ BUS ECONOMICO =============" << endl;
            cout << ANSI_COLOR_RESET;
            cout << ANSI_COLOR_YELLOW;
            cout << "\t\tEn nuestro servicio encontrarás puertos usb para mantenerte conectado en todo momento así como asientos" << endl;
            cout << "\t\tergonómicos cama de 150° que te garantizarán el mejor descanso " << endl;
            cout << "\t\t* Asientos 150°" << endl;
            cout << "\t\t* Bus climatizado" << endl;
            cout << "\t\t* Baño quimico" << endl;
            cout << "\t\t* Monitoreado por GPS" << endl;
            cout << endl;
            cout << endl;
            cout << ANSI_COLOR_RESET;
    }
    static void Borde() {

	int n = 100; 
	
	printf("\n");
	
		for(int ren=1; ren<=n ; ren++) {
	  		for(int col=1; col<=n; col++) {
				if(ren == 1 || ren == n || col== 1 || col==n) {
					printf("*");  
				}
	  			else 
	  			{
	  				printf(" ");
				}
			}
		printf("\n");
	  }
    }
};