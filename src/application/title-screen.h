#include <iostream>

using namespace std;

class TitleScreen {
    private:
        static const int screenWidth = 80;
        static void drawnBorder();
        static void drawnContent(string content);
        static void render();
    public:
        TitleScreen();
        static void load();
};