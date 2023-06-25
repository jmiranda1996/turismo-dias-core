#ifndef Global_H
#define Global_H

#include <iostream>
#include "../domain/entities/Admin.h"
#include "../domain/entities/Client.h"

using namespace std;
using namespace tdc::domain::entities;

class Global {
    public:
        static bool isLogin;
        static Admin* admin;
        static Client* client;
};

#endif