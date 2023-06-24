#include <iostream>
#include "Admin.h"
#include "../shared/User.h"
#include "../shared/UserInfo.h"
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    Admin::Admin(): User() { };
    Admin::Admin(
        string _documentId,
        DocumentType _documentType,
        string _username, 
        string _emailAddress, 
        UserInfo* _userInfo
    ): User(_documentId, _documentType, _username, _emailAddress, _userInfo) {
        ::User::userType = ::Administrator;
    };
};