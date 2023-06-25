#include <iostream>
#include "GenericInterface.h"

using namespace std;

namespace tdc::domain::interfaces {
    template <typename T>
    T* GenericInterface<T>::get(int index) { };
    template <typename T>
    void GenericInterface<T>::insertOrUpdate(T* newEntity) { };
    template <typename T>
    void GenericInterface<T>::remove(int index) { };
}