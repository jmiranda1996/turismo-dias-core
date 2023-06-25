#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <random>
#include <climits>
#include <algorithm>
#include <functional>
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

unsigned char random_char() {
    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dis(0, 255);
    return static_cast<unsigned char>(dis(gen));
}

//referencia: https://lowrey.me/guid-generation-in-c-11/
string Utils::generateGUUID()
{
    std::stringstream ss;
    for(int i = 0; i < 32; i++) {
        auto rc = random_char();
        std::stringstream hexstream;
        hexstream << std::hex << int(rc);
        auto hex = hexstream.str(); 
        ss << (hex.length() < 2 ? '0' + hex : hex);
    }        
    return ss.str();
}