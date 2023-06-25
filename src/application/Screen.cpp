#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include "Colors.h"
#include "Screen.h"

using namespace std;

void Screen::drawnBorder() {
    cout << ANSI_COLOR_BLUE;
    cout << setfill( '*' ) << setw(screenWidth) << '*' <<  endl;
    cout << ANSI_COLOR_RESET;
};

void Screen::drawnContent(string content, bool bold = false, string color = ANSI_COLOR_RESET) {
    cout << ANSI_COLOR_BLUE << "* " << ANSI_COLOR_RESET << left << setfill(' ');
    cout << color;
    if (bold) cout << ANSI_STYLE_BOLD;
    cout << setw(screenWidth - 3) << content;
    cout << ANSI_COLOR_RESET;
    cout << ANSI_COLOR_BLUE << "* " << ANSI_COLOR_RESET << endl;
};

void Screen::render() { };
 
void Screen::load() { };

 