#include <iostream>
#include "../shared/User.h"
#include "../shared/UserInfo.h"
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    class Client: public User  {
        private:
            // historial de reservas/viajes
            // puntos acumulados
            // consultas
            // tipo de cliente
            // ...
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