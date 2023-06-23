#ifndef HashTable_H
#define HashTable_H

#include <iostream>
#include "HashTableItem.h"

using namespace std;

namespace tdc::infraestructure::structures {
    template <typename T>
    class HashTable {
        private:
            uint maxSize;
            uint size;
            HashTableItem<T>** items;
        public:
            HashTable(uint _maxSize);

            T* get(uint key);
            void insert(uint key, T* newItem);
            void remove(uint key);
            uint getSize();
            uint getMaxSize();
    };
};

#endif