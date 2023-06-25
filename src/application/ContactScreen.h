#include <iostream>
#include "Screen.h"

using namespace std;

class ContactScreen: public Screen {
    private:
        static void displayInfo();
        static void render();
    public:
        static void load();
};