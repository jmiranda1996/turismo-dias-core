#include <iostream>
#include <string>
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_STYLE_BOLD    "\x1b[1m"
#define ANSI_COLOR_RESET   "\x1b[0m"
using namespace std;

class Login {
    private:
    string usuario;
    string contrasena;

    Login(string usuario, string contrasena){
        this-> usuario = usuario;
        this-> contrasena = contrasena;
    };

    ~Login(){};

    string getUsuario(){ return usuario; }
    string getContrasena() { return contrasena; }
    void setUsuario (string user){ usuario = user; }
    void setContrasena (string password){ contrasena = password; }

    void imprimirPantalla(){
        cout << ANSI_COLOR_YELLOW;
        cout << ANSI_STYLE_BOLD;
        cout << "\t\t\t\t\t\t\t\t INICIAR SESIÓN " << endl;
        cout << ANSI_COLOR_RESET;
        cout << "Usuario: ";
        cin >> usuario;
        cout << "Contrasena: ";
        cin >> contrasena;
    }

};