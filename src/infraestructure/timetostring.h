#include <ctime>
#include <string>
#include <iostream>
using namespace std;

// referencia: https://cplusplus.com/reference/ctime/strftime/

string tiempoToString(time_t tiempo) {
    struct tm* tiempoinfo;
    char buffer[80]; //donde se almacenara, 80 es lo generico.
    // estructura del tiempo
    
    tiempoinfo = localtime(&tiempo);
    
    // darle el formato
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", tiempoinfo);

    // crear el string apartir del buffer.
    string tiempostring(buffer);
    return tiempostring
}