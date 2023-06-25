#include <iostream>
#include "Global.h"
#include "../domain/entities/Admin.h"
#include "../domain/entities/Client.h"

using namespace std;
using namespace tdc::domain::entities;

bool Global::isLogin = false;
Admin* Global::admin = nullptr;
Client* Global::client = nullptr;