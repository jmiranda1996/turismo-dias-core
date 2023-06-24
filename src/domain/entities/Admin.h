#ifndef Admin_H
#define Admin_H

#include <iostream>
#include "../shared/User.h"
#include "../shared/UserInfo.h"
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    class Admin: public User  {
        private:
        public:
            Admin();
            Admin(
                string _documentId, 
                DocumentType _documentType,
                string _username, 
                string _emailAddress, 
                UserInfo* _userInfo = nullptr
            );
    };
};

#endif