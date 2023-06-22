#include <iostream>
#include "Passenger.h"
#include "../shared/User.h"
#include "../shared/UserInfo.h"
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    Passenger::Passenger(): User() { };
    Passenger::Passenger(
        string _documentId,
        DocumentType _documentType,
        string _username, 
        string _emailAddress, 
        UserInfo* _userInfo
    ): User(_documentId, _documentType, _username, _emailAddress, _userInfo) {
        ::User::userType = ::Unknown;
    };
};