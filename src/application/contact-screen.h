#include <iostream>

using namespace std;

class ContactScreen {
    private:
        static const int screenWidth = 80;
        static void drawnBorder();
        static void drawnContent(string content, bool bold, string color);
        static void displayInfo();
        static void render();
    public:
        ContactScreen();
        static void load();
};