#ifndef Client_H
#define Client_H

#include <iostream>
#include "Booking.h"
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
            LinkedList<Booking*>* bookings;
            ClientType clientType;
            // consultas
        public:
            Client();
            Client(
                string _documentId, 
                string _username, 
                string _emailAddress, 
                UserInfo* _userInfo = nullptr
            );
    };
};

#endif