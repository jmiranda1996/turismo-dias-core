#include <iostream>
#include "Screen.h"

using namespace std;

class BookingScreen: public Screen {
    private:
        static void render();
    public:
        static void load();
};