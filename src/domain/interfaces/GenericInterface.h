#ifndef GenericInterface_H
#define GenericInterface_H

#include <iostream>
 
using namespace std;

namespace tdc::domain::interfaces {
    template <typename T>
    class GenericInterface {
        public:
            virtual T* get(int index);
            virtual void insertOrUpdate(T* newEntity);
            virtual void remove(int index);
    };
}

#endif