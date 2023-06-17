#include <iostream>
#include "Stopover.h"

using namespace std;

namespace tdc::domain::shared {
    Stopover::Stopover() {
        address = "";
        city = "";
    };
    Stopover::Stopover(string _address, string _city) {
        address = _address;
        city = _city;
    };
};
