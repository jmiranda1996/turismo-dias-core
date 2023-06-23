#ifndef GenericInterface_H
#define GenericInterface_H

#include <iostream>
 
using namespace std;

namespace tdc::domain::interfaces {
    template <typename T>
    class GenericInterface {
        public:
            virtual T* get(uint index);
            virtual void insertOrUpdate(T* newEntity);
            virtual void remove(uint index);
    };
}

#endif