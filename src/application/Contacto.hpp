#include <iostream>
#include <stdlib.h>
#include <string>
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_STYLE_BOLD    "\x1b[1m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_BLUE    "\x1b[34m"

#define ANSI_COLOR_RED     "\x1b[31m"
using namespace std;

class Contacto {
    public:  
    static void Mostrar_contactos() {

            cout << ANSI_COLOR_RED;
            cout << ANSI_STYLE_BOLD;
            cout << endl;
            cout << "\t Pasajes:" << endl;
            cout << ANSI_COLOR_RESET;
            cout << ANSI_COLOR_YELLOW;
            cout << "\t Cel: (+51) 966317940" << endl;
            cout << "\t Tel: (01) 3981733" << endl;
            cout << "\tEmail: pasajes@turismodias.com " << endl;
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