#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <cstring>
#include "Global.h"
#include "Colors.h"
#include "SignInScreen.h"
#include "../domain/entities/Client.h"
#include "../domain/shared/UserInfo.h"
#include "../infraestructure/repository/ClientRepository.h"
#include "../infraestructure/structures/LinkedList.h"

using namespace std;
using namespace tdc::domain::entities;
using namespace tdc::domain::shared;
using namespace tdc::infraestructure::repository;
// using namespace tdc::infraestructure::structures;

void SignInScreen::render() {
    drawnBorder();
    drawnContent("", false, ANSI_COLOR_GREEN);

    drawnContent("============ INICIAR SESION =============", false, ANSI_COLOR_PURPLE);
    drawnContent("", false, ANSI_COLOR_GREEN);

    string prompt;
    string username;
    string password;

    prompt = "Ingrese usuario:";
    drawnContent(prompt, false, ANSI_COLOR_GREEN);
    getline(cin >> ws, username);

    prompt = "Ingrese contraseña:";
    drawnContent(prompt, false, ANSI_COLOR_GREEN);
    getline(cin >> ws, password);
    
    ClientRepository* repository = ClientRepository::GetInstance();
    LinkedList<Client> clients = repository->getAll();

    for (int i = 0; i < clients.getLength(); i++)
    {
        if (clients.elementAt(i).getPasswordHash() == password) {
            Global::isLogin = true;
            Client client = clients.elementAt(i);
            Global::client = &client;
        }
    }
    
    if (Global::isLogin) {
        prompt = "Bienvenido!";
        drawnContent(prompt, true, ANSI_COLOR_YELLOW);
    } else {
        drawnContent("Usuario y/o contraseña no encontrados", true, ANSI_COLOR_YELLOW);
    }

    drawnContent(" ", false, ANSI_COLOR_GREEN);
    drawnBorder();
};
 
void SignInScreen::load() {
    render();
};