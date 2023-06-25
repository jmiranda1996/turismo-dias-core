#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <cstring>
#include "Colors.h"
#include "Global.h"
#include "ProfileScreen.h"

using namespace std;

void ProfileScreen::render() {
    drawnBorder();
    drawnContent("", false, ANSI_COLOR_GREEN);

    drawnContent("============ Perfil =============", false, ANSI_COLOR_PURPLE);
    drawnContent("", false, ANSI_COLOR_GREEN);
    if (!Global::isLogin) {
        drawnContent("Debe iniciar sesion para ver su perfil", true, ANSI_COLOR_RED);
        return;
    }

    if (Global::client != nullptr) {
        drawnContent("Usuario: " + Global::client->getUsername(), false, ANSI_COLOR_GREEN);
        drawnContent("Correo: " + Global::client->getEmailAddress(), false, ANSI_COLOR_GREEN);
        drawnContent("Nombres: " + Global::client->getUserInfo()->getFirstName(), false, ANSI_COLOR_GREEN);
        drawnContent("Apellidos: " + Global::client->getUserInfo()->getPhoneNumber(), false, ANSI_COLOR_GREEN);
        drawnContent("Puntos acumulados: " + to_string(Global::client->getPoints()), false, ANSI_COLOR_GREEN);
    }
    else if (Global::admin != nullptr) {
        drawnContent("Usuario: " + Global::admin->getUsername(), false, ANSI_COLOR_GREEN);
        drawnContent("Correo: " + Global::admin->getEmailAddress(), false, ANSI_COLOR_GREEN);
        drawnContent("Nombres: " + Global::admin->getUserInfo()->getFirstName(), false, ANSI_COLOR_GREEN);
        drawnContent("Apellidos: " + Global::admin->getUserInfo()->getPhoneNumber(), false, ANSI_COLOR_GREEN);
    }

    drawnContent(" ", false, ANSI_COLOR_GREEN);
    drawnBorder();
};
 
void ProfileScreen::load() {
    render();
};