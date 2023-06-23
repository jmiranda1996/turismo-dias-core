#include <iostream>
#include "HashTable.h"
#include "HashTableItem.h"

#include "../../domain/entities/Client.h"

using namespace std;

namespace tdc::infraestructure::structures {
    template <typename T>
    HashTable<T>::HashTable(uint _maxSize) {
        maxSize = _maxSize;
        items = new HashTableItem<T>*[maxSize];

        for (int i = 0; i < maxSize; i++)
        {
            items[i] = nullptr;
        }

        size = 0;
    }

    template <typename T>
    T* HashTable<T>::get(uint key) {
        return items[key]->getValue();
    }

    template <typename T>
    void HashTable<T>::insert(uint key, T* newItem) {
        HashTableItem<T>* newHashTableItem = new HashTableItem<T>(key, newItem);
        items[key] = newHashTableItem;
    }

    template <typename T>
    void HashTable<T>::remove(uint key) {
        if (key <= maxSize) {
            items[key] = nullptr;
        }
    }

    template <typename T>
    uint HashTable<T>::getSize() {
        return size;
    }

    template <typename T>
    uint HashTable<T>::getMaxSize() {
        return maxSize;
    }
    
    template class HashTable<tdc::domain::entities::Client>;
};