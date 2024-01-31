#include "TUI.h"


TUI::TUI(){}

void TUI::mainLoop(){

    cout << "Enter two variables separated by a space: ";
    cin >> fieldDimX >> fieldDimY;

    cout << "Enter the starting position X Y F:  ";
    cin >> startX >> startY >> direction;

    cout << "Enter command: ";
    cin >> command;

    Simulator test(fieldDimX,fieldDimY,startX,startY,direction,command);
    test.printMatrix();
}
