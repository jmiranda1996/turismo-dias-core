#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>

using namespace std;

namespace tdc::infraestructure::structures {
    template <typename T>
    class Node {
        public:
            T element;
            Node* next;

            Node(T newElement) {
                element = newElement;
                next = nullptr;
            }
    };

    template <typename T>
    class LinkedList {
        private:
            Node<T>* head;
            int length;

        public:
            LinkedList() {
                head = nullptr;
                length = 0;
            }

            int getLength() {
                return length;
            }

            void insert(T newElement) {
                Node<T>* newNode = new Node<T>(newElement);
                newNode->next = head;
                if(newNode != nullptr) {
                    head = newNode;
                    length++;
                }
            }

            T elementAt(int index) {
                if (index < 0 || index >= length) {
                    throw out_of_range("Elemento no encontrado");
                }
                Node<T>* current = head;
                for (int i = 0; i < index; i++) {
                    current = current->next;
                }
                return current->element;
            }

            T firstOrDefault() {
                return head->element;
            }
    };
}

#endif