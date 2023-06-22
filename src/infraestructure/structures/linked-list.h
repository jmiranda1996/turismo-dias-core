#include <iostream>
using namespace std;

namespace tdc::infraestructure::structures {
    template <typename T>
    class Node {
    public:
        T dato;
        Node* siguiente;
        Node* anterior;

        Node(T valor) {
            dato = valor;
            siguiente = nullptr;
            anterior = nullptr;
        }
    };

    template <typename T>
    class LinkedList {
    private:
        Node<T>* cabeza;
        Node<T>* cola;
        int length;

    public:
        LinkedList() {
            cabeza = nullptr;
            cola = nullptr;
            length = 0;
        }

        bool estaVacia() {
            return (cabeza == nullptr);
        }

        int obtenerlength() {
            return length;
        }

        void insertarAlInicio(T valor) {
            Node<T>* nuevoNode = new Node<T>(valor);
            if (estaVacia()) {
                cabeza = nuevoNode;
                cola = nuevoNode;
            }
            else {
                nuevoNode->siguiente = cabeza;
                cabeza->anterior = nuevoNode;
                cabeza = nuevoNode;
            }
            length++;
        }

        void insertarAlFinal(T valor) {
            Node<T>* nuevoNode = new Node<T>(valor);
            if (estaVacia()) {
                cabeza = nuevoNode;
                cola = nuevoNode;
            }
            else {
                cola->siguiente = nuevoNode;
                nuevoNode->anterior = cola;
                cola = nuevoNode;
            }
            length++;
        }

        void mostrarLista() {
            if (estaVacia()) {
                cout << "La lista está vacía." << endl;
                return;
            }
            Node<T>* nodoActual = cabeza;
            while (nodoActual != nullptr) {
                cout << nodoActual->dato << " ";
                nodoActual = nodoActual->siguiente;
            }
            cout << endl;
        }
        T obtenerDatoEnPosicion(int posicion) {
            if (posicion < 0 || posicion >= length) {
                throw out_of_range("Posición inválida");
            }
            Node<T>* nodoActual = cabeza;
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
}