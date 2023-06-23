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
    string sexo;
    string correo;
    string direccion;
    string telefono;
    string usuario;
    string contrasena;
    
    public:
    signUp (){
        this-> nombre = "";
        this-> apellido = "";
        this-> sexo = "";
        this-> correo = "";
        this-> direccion = "";
        this-> telefono = "";
        this-> usuario = "";
        this-> contrasena = "";
    };

    signUp (string nombre, string apellido, string sexo, string correo, string direccion, string telefono, string usuario, string contrasena){
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
    void setNombre (string name){ nombre = name; }
    void setContrasena (string password){ contrasena = password; }

    void Registrar (){
        cout << ANSI_COLOR_YELLOW;
        cout << ANSI_STYLE_BOLD;
        cout << "\t\t\t\t\t\t\t\t CREAR UNA CUENTA " << endl;
        cout << ANSI_COLOR_RESET;
        cout << "NOMBRE: ";
        cin >> this->nombre;
        cout << "APELLIDO: ";
        cin >> this->apellido;
        cout << "SEXO: ";
        cin >> this->sexo;
        cout << "CORREO: ";
        cin >> this->correo;
        cout << "DIRECCION: ";
        cin >> this->direccion;
        cout << "TELEFONO: ";
        cin >> this->telefono;
        cout<< "USUARIO: ";
        cin >> this->usuario;
        cout << "CONTRASENA: ";
        cin >> this->contrasena;
        cout << "\n\n --- LOS DATOS SE REGISTRARON CORRECTAMENTE --- " << endl << endl;
        sleep(1);
        system("clear");
    }

};