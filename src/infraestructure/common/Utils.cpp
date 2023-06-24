#include <iostream>
#include "Utils.h"

using namespace std;

uint Utils::hashFunction(string uuid, uint size)
{
    unsigned long sum = 0;

    for (int i = 0; uuid[i]; i++)
        sum += uuid[i];

    return sum % size;
}

// referencia: https://cplusplus.com/reference/ctime/strftime/
string Utils::timeToString(time_t time)
{
    struct tm* tiempoinfo;
    char buffer[80];
    tiempoinfo = localtime(&time);
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", tiempoinfo);
    string tiempostring(buffer);

    return tiempostring;
}