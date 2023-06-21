#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "title-screen.h"
#include "main-screen.hpp"

using namespace std;

void TitleScreen::drawnBorder() {
    cout << std::setfill( '*' ) << setw(screenWidth) << '*' <<  endl;
};

void TitleScreen::drawnContent(string content) {
    cout << "* " << std::left << setfill(' ');
    cout << setw(screenWidth - 3) << content << '*' << endl;
};

void TitleScreen::render() {
    std::vector<std::string> vec;
    vec.push_back("___ _  _ ____ _ ____ _  _ ____    ___  _ ____ ____");
    vec.push_back(" |  |  | |__/ | [__  |\\/| |  |    |  \\ | |__| [__");
    vec.push_back(" |  |__| |  \\ | ___] |  | |__|    |__/ | |  | ___]");
    vec.push_back("");
    vec.push_back("Escoge una opcion:");
    vec.push_back("");
    vec.push_back("1. Ingresar como invitado");
    vec.push_back("2. Iniciar sesion");
    vec.push_back("3. Registrase");
    vec.push_back("4. Salir");
    
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
    do {
        render();

        cin >> option;

        switch (option)
        {
            case 1:
                MainScreen::Mostrar_menu();
                break;
            case 2:
            case 3:
                cout << "Hola menu" << endl;
                break;
            
            default:
                break;
        }
    } while (option != 4);
};

 