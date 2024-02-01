#include <iostream>
#include "include/TUI.h"

int main(int, char**){
    TUI start = TUI();
    start.mainLoop();
    return EXIT_SUCCESS;
}
