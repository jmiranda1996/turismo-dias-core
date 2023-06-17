#include <iostream>
using namespace std;

template <typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(T valor) {
        dato = valor;
        siguiente = nullptr;
        anterior = nullptr;
    }
};

template <typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
    int tamaño;

public:
    ListaEnlazada() {
        cabeza = nullptr;
        cola = nullptr;
        tamaño = 0;
    }

    bool estaVacia() {
        return (cabeza == nullptr);
    }

    int obtenerTamaño() {
        return tamaño;
    }

    void insertarAlInicio(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        if (estaVacia()) {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        }
        else {
            nuevoNodo->siguiente = cabeza;
            cabeza->anterior = nuevoNodo;
            cabeza = nuevoNodo;
        }
        tamaño++;
    }

    void insertarAlFinal(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        if (estaVacia()) {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        }
        else {
            cola->siguiente = nuevoNodo;
            nuevoNodo->anterior = cola;
            cola = nuevoNodo;
        }
        tamaño++;
    }

    void mostrarLista() {
        if (estaVacia()) {
            cout << "La lista está vacía." << endl;
            return;
        }
        Nodo<T>* nodoActual = cabeza;
        while (nodoActual != nullptr) {
            cout << nodoActual->dato << " ";
            nodoActual = nodoActual->siguiente;
        }
        cout << endl;
    }
    T obtenerDatoEnPosicion(int posicion) {
        if (posicion < 0 || posicion >= tamaño) {
            throw out_of_range("Posición inválida");
        }
        Nodo<T>* nodoActual = cabeza;
        for (int i = 0; i < posicion; i++) {
            nodoActual = nodoActual->siguiente;
        }
        return nodoActual->dato;
    }

    T obtenerDatoInicio() {
        if (estaVacia()) {
            throw runtime_error("La lista está vacía");
        }
        return cabeza->dato;
    }

    T obtenerDatoFin() {
        if (estaVacia()) {
            throw runtime_error("La lista está vacía");
        }
        return cola->dato;
    }
};