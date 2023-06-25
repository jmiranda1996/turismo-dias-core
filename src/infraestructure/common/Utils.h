#ifndef Utils_H
#define Utils_H

#include <iostream>

using namespace std;

class Utils {
    public:
        static uint hashFunction(string uuid, uint size);
        static string timeToString(time_t time);
        static string generateGUUID();
        static string passwordHash(string _password);
        static bool validatePassword(string _password, string _passwordHash);
};

#endif

#include <ctime>
#include <string>
#include <iostream>
using namespace std;