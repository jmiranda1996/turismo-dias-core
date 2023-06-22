#ifndef Client_H
#define Client_H

#include <iostream>
#include "../shared/User.h"
#include "../shared/UserInfo.h"
#include "../shared/Enums.h"
#include "../../infraestructure/structures/linked-list.h"

using namespace std;
using namespace tdc::domain::shared;
using namespace tdc::infraestructure::structures;

namespace tdc::domain::entities {
    class Client: public User  {
        private:
            uint points;
            ClientType clientType;
        public:
            Client();
            Client(
                string _documentId, 
                DocumentType _documentType,
                string _username, 
                string _emailAddress, 
                UserInfo* _userInfo = nullptr
            );
    };
};

#endif