#include <iostream>
#include "Screen.h"

using namespace std;

class MainScreen: public Screen {
    private:
        static void render();
    public:
        static void load();
};