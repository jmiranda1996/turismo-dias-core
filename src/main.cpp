#include <iostream>
#include "domain/entities/Client.h"
#include "domain/shared/User.h"

using namespace std;
// using namespace td;

int main(int argc, char *argv[]) {
    
    cout << "Turismo Dias Core" << endl;

    tdc::domain::shared::User * newClient = new tdc::domain::entities::Client();
    newClient->setUsername("Jerson Miranda");

    cout << newClient->getUsername() << endl;

    cin.get();
}