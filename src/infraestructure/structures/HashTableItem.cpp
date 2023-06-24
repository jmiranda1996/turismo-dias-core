#include <iostream>
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
    
    template class HashTableItem<tdc::domain::entities::Admin>;
    template class HashTableItem<tdc::domain::entities::Agency>;
    template class HashTableItem<tdc::domain::entities::Booking>;
    template class HashTableItem<tdc::domain::entities::Bus>;
    template class HashTableItem<tdc::domain::entities::Client>;
    template class HashTableItem<tdc::domain::entities::ContactForm>;
    template class HashTableItem<tdc::domain::entities::Driver>;
    template class HashTableItem<tdc::domain::entities::Passenger>;
    template class HashTableItem<tdc::domain::entities::Schedule>;
}