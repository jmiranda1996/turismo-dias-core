#ifndef Utils_H
#define Utils_H

#include <iostream>

using namespace std;

uint hashFunction(string uuid, uint size)
{
    unsigned long sum = 0;

    for (int i = 0; uuid[i]; i++)
        sum += uuid[i];

    return sum % size;
}

#endif