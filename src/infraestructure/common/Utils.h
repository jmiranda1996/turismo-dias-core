#ifndef Utils_H
#define Utils_H

#include <iostream>

using namespace std;

class Utils {
    public:
        static uint hashFunction(string uuid, uint size);
        static string timeToString(time_t time);
        static string generateGUUID();
};

#endif

#include <ctime>
#include <string>
#include <iostream>
using namespace std;