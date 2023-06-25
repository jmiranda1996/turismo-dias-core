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
        DocumentType _documentType,
        string _username, 
        string _emailAddress, 
        UserInfo* _userInfo
    ): User(_documentId, _documentType, _username, _emailAddress, _userInfo) {
        ::User::userType = ::Customer;
        if (_userInfo == nullptr) clientType = Member; 
    };

    int Client::getPoints() { return points; };
    ClientType Client::getClientType() { return clientType; };

    void Client::setPoints(int _points) { points = _points; };
    void Client::setClientType(ClientType _clientType) { clientType = _clientType; }
};