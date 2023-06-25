#ifndef Screen_H
#define Screen_H

#include <iostream>

using namespace std;

class Screen {
    protected:
        static const int screenWidth = 80;
        static void drawnBorder();
        static void drawnContent(string content, bool bold, string color);
        static void render();
    public:
        Screen();
        static void load();
};

#endif