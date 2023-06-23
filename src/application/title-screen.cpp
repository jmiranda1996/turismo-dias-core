#include <iostream>
#include<unistd.h>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include "title-screen.h"
#include "main-screen.hpp"
#include "signUp.hpp"
#include "Login.hpp"

using namespace std;

void TitleScreen::drawnBorder() {
    cout << setfill( '*' ) << setw(screenWidth) << '*' <<  endl;
};

void TitleScreen::drawnContent(string content) {
    cout << "* " << left << setfill(' ');
    cout << setw(screenWidth - 4) << content << '*' << endl;
};

void TitleScreen::render() {
    vector<string> vec;
    vec.push_back(" ___ _  _ ____   _  ____ _  _  ____    ___   _ ____ ____ ");
    vec.push_back("  |  |  | |__/   |  [__  |\\/| |  |    |  \\ | |__| [__  ");
    vec.push_back("  |  |__| |  \\  |  ___] |   | |__|    |__/  | |  | ___] ");
    vec.push_back("");
    vec.push_back("");
    vec.push_back("1. Ingresar como invitado");
    vec.push_back("2. Iniciar sesion");
    vec.push_back("3. Registrase");
    vec.push_back("4. Salir");
    vec.push_back("");
    vec.push_back("Escoge una opcion:");
    
    drawnBorder();
    drawnContent(" ");

    for (int i=0; i<vec.size(); i++) {
        drawnContent(vec[i]);
    }

    drawnContent(" ");
    drawnBorder();
};
 
void TitleScreen::load() {
    int option = 0;
    signUp registro;
    Login sesion;
    do {
        render();
        cin >> option;
        
        system("clear");
        switch (option)
        {
            case 1:
                MainScreen::Mostrar_menu();
                break;
            case 2:
                sesion.imprimirPantalla();
                MainScreen::Mostrar_menu();
                break;
            case 3:
                registro.Registrar();
                MainScreen::Mostrar_menu();
            default:
                cout << "Esa opción no es valida";
                break;
        }
    } while (option != 4);
};

 