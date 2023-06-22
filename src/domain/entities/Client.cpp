#include <iostream>
#include "Client.h"
#include "../shared/User.h"
#include "../shared/UserInfo.h"
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    Client::Client(): User() { };
    Client::Client(
        string _documentId, 
        string _username, 
        string _emailAddress, 
        UserInfo* _userInfo
    ): User(_documentId, _username, _emailAddress, _userInfo) {
        ::User::userType = ::Client;
        if (_userInfo == nullptr) clientType = Guest; 
    };
};