#include <iostream>
#include "user.h"

using namespace std;
using namespace td;

int main(int argc, char *argv[]) {
    
    cout << "Turismo Dias Core" << endl;

    domian::shared::User* newUser = new domian::shared::User();

    cout << newUser->getId() << endl;

    cin.get();
}