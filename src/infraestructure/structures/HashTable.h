#ifndef HashTable_H
#define HashTable_H

#include <iostream>
#include "HashTableItem.h"

using namespace std;

namespace tdc::infraestructure::structures {
    template <typename T>
    class HashTable {
        private:
            int maxSize;
            int size;
            HashTableItem<T>** items;
        public:
            HashTable(int _maxSize);

            T* get(int key);
            void insert(int key, T* newItem);
            void remove(int key);
            int getSize();
            int getMaxSize();
    };
};

#endif