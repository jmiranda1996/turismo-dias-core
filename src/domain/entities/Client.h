#ifndef Client_H
#define Client_H

#include <iostream>
#include "../shared/User.h"
#include "../shared/UserInfo.h"
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    class Client: public User  {
        private:
            int points;
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

            int getPoints();
            ClientType getClientType();

            void setPoints(int _points);
            void setClientType(ClientType _clientType);
    };
};

#endif