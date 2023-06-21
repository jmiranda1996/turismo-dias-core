#include <iostream>
#include <string>
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_STYLE_BOLD    "\x1b[1m"
#define ANSI_COLOR_RESET   "\x1b[0m"
using namespace std;

class signUp {
    private:
    string nombre;
    string apellido;
    char sexo;
    string correo;
    string direccion;
    string telefono;
    string usuario;
    string contrasena;

    signUp (string nombre, string apellido, char sexo, string correo, string direccion, string telefono, string usuario, string contrasena){
        this-> nombre = nombre;
        this-> apellido = apellido;
        this-> sexo = sexo;
        this-> correo = correo;
        this-> direccion = direccion;
        this-> telefono = telefono;
        this-> usuario = usuario;
        this-> contrasena = contrasena;
    };

    ~signUp(){};

    string getUsuario(){ return usuario; }
    string getContrasena() { return contrasena; }
    void setUsuario (string user){ usuario = user; }
    void setContrasena (string password){ contrasena = password; }

    void imprimirPantalla(){
        cout << ANSI_COLOR_YELLOW;
        cout << ANSI_STYLE_BOLD;
        cout << "\t\t\t\t\t\t\t\t CREAR UNA CUENTA " << endl;
        cout << ANSI_COLOR_RESET;
        cout << "Nombre ";
        cin >> usuario;
        cout << "Apellido: ";
        cin >> contrasena;
        cout << "Sexo (M o F): ";
        cin >> sexo;
        cout << "Correo: ";
        cin >> correo;
        cout << "Direccion: ";
        cin >> direccion;
        cout << "Telefono: ";
        cin >> telefono;
    }

};