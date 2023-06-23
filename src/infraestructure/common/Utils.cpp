#include <iostream>
#include "Utils.h"

using namespace std;

uint Utils::hashFunction(string uuid, uint size)
{
    unsigned long sum = 0;

    for (int i = 0; uuid[i]; i++)
        sum += uuid[i];

    return sum % size;
}