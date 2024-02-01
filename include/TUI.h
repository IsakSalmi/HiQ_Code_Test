#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

#include "Simulator.h"

using namespace std;

class TUI
{
private:
    int fieldDimX, fieldDimY; 
    int startX, startY;
    char direction;
    string command;
    bool checkDir(char Dir);
    bool checkCommand(string command);


public:
    void mainLoop();
    TUI();
};