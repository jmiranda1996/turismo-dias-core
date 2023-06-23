#include <iostream>
#include "HashTableItem.h"

#include "../../domain/entities/Client.h"

using namespace std;

namespace tdc::infraestructure::structures {
    template <typename T>
    HashTableItem<T>::HashTableItem() {
        key = 0;
        value = nullptr;
    };

    template <typename T>
    HashTableItem<T>::HashTableItem(uint _key, T* _value) {
        key = _key;
        value = _value;
    };

    template <typename T>
    uint HashTableItem<T>::getKey() {
        return key;
    }

    template <typename T>
    T* HashTableItem<T>::getValue() {
        return value;
    }

    template <typename T>
    void HashTableItem<T>::setKey(uint _key) {
        key = _key;
    }

    template <typename T>
    void HashTableItem<T>::setValue(T* _value) {
        value = _value;
    }
    
    template class HashTableItem<tdc::domain::entities::Client>;
}