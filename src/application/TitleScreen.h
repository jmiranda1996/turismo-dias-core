#include <iostream>
#include "Screen.h"

using namespace std;

class TitleScreen: public Screen {
    private:
        static void render();
    public:
        static void load();
};