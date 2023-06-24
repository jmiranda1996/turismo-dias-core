#include <iostream>
#include "HashTable.h"
#include "HashTableItem.h"

#include "../../domain/entities/Admin.h"
#include "../../domain/entities/Agency.h"
#include "../../domain/entities/Booking.h"
#include "../../domain/entities/Bus.h"
#include "../../domain/entities/Client.h"
#include "../../domain/entities/ContactForm.h"
#include "../../domain/entities/Driver.h"
#include "../../domain/entities/Passenger.h"
#include "../../domain/entities/Schedule.h"

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
        if (items[key] != nullptr) {
            return items[key]->getValue();
        }
        return nullptr;
    }

    template <typename T>
    void HashTable<T>::insert(uint key, T* newItem) {
        HashTableItem<T>* newHashTableItem = new HashTableItem<T>(key, newItem);
        items[key] = newHashTableItem;
        size++;
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
    
    template class HashTable<tdc::domain::entities::Admin>;
    template class HashTable<tdc::domain::entities::Agency>;
    template class HashTable<tdc::domain::entities::Booking>;
    template class HashTable<tdc::domain::entities::Bus>;
    template class HashTable<tdc::domain::entities::Client>;
    template class HashTable<tdc::domain::entities::ContactForm>;
    template class HashTable<tdc::domain::entities::Driver>;
    template class HashTable<tdc::domain::entities::Passenger>;
    template class HashTable<tdc::domain::entities::Schedule>;
};