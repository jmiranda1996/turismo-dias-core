#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <cstring>
#include "Colors.h"
#include "SignUpScreen.h"
#include "../domain/entities/Client.h"
#include "../domain/shared/UserInfo.h"
// #include "../domain/entities/Schedule.h"
#include "../infraestructure/repository/ClientRepository.h"
// #include "../infraestructure/repository/ScheduleRepository.h"
// #include "../infraestructure/structures/LinkedList.h"
// #include "../infraestructure/common/Utils.h"

using namespace std;
using namespace tdc::domain::entities;
using namespace tdc::domain::shared;
using namespace tdc::infraestructure::repository;
// using namespace tdc::infraestructure::structures;

void SignUpScreen::render() {
    drawnBorder();
    drawnContent("", false, ANSI_COLOR_GREEN);

    drawnContent("============ REGISTRO =============", false, ANSI_COLOR_PURPLE);
    drawnContent("", false, ANSI_COLOR_GREEN);

    string prompt;
    string username;
    string email;
    string password;
    string confirmPassword;
    string documentId;
    string firtName;
    string lastName;
    string address;
    string phone;
    string gender;

    prompt = "Ingrese usuario:";
    drawnContent(prompt, false, ANSI_COLOR_GREEN);
    getline(cin >> ws, username);

    prompt = "Ingrese correo:";
    drawnContent(prompt, false, ANSI_COLOR_GREEN);
    getline(cin >> ws, email);

    do {
        prompt = "Ingrese contraseña:";
        drawnContent(prompt, false, ANSI_COLOR_GREEN);
        getline(cin >> ws, password);

        prompt = "Confirma contraseña:";
        drawnContent(prompt, false, ANSI_COLOR_GREEN);
        getline(cin >> ws, confirmPassword);

        if(password != confirmPassword) drawnContent("La contraseña debe coincidir", false, ANSI_COLOR_GREEN);
    } while (password != confirmPassword);
    
    prompt = "Ingrese nro de documento:";
    drawnContent(prompt, false, ANSI_COLOR_GREEN);
    getline(cin >> ws, documentId);

    prompt = "Ingrese nombres:";
    drawnContent(prompt, false, ANSI_COLOR_GREEN);
    getline(cin >> ws, firtName);

    prompt = "Ingrese apellidos:";
    drawnContent(prompt, false, ANSI_COLOR_GREEN);
    getline(cin >> ws, firtName);

    prompt = "Ingrese direccion:";
    drawnContent(prompt, false, ANSI_COLOR_GREEN);
    getline(cin >> ws, address);

    prompt = "Ingrese telefono:";
    drawnContent(prompt, false, ANSI_COLOR_GREEN);
    getline(cin >> ws, phone);

    prompt = "Ingrese sexo (M) (F):";
    drawnContent(prompt, false, ANSI_COLOR_GREEN);
    getline(cin >> ws, gender);

    Client* entity = new Client();
    entity->setDocumentId(documentId);
    entity->setClientType(Member);
    entity->setDocumentType(DNI);
    entity->setPoints(0);
    entity->setStatus(Active);
    entity->setUsername(username);
    entity->setPasswordHash(password);
    entity->setEmailAddress(email);
    UserInfo* userInfo = new UserInfo();
    userInfo->setFirstName(firtName);
    userInfo->setLastName(lastName);
    userInfo->setPhoneNumber(phone);
    userInfo->setAddress(address);
    userInfo->setGender(gender[0]);
    entity->setUserInfo(userInfo);
    ClientRepository* repository = ClientRepository::GetInstance();
    repository->insertOrUpdate(entity);

    prompt = "Registro realizada con exito!";
    drawnContent(prompt, true, ANSI_COLOR_YELLOW);

    drawnContent(" ", false, ANSI_COLOR_GREEN);
    drawnBorder();
};
 
void SignUpScreen::load() {
    render();
};