#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Simulator.h"

using namespace std;

class TUI
{
private:
int fieldDimX, fieldDimY; 
int startX, startY;
char direction;
string command;


public:
    void mainLoop();
    TUI();
};