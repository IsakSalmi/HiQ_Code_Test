#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Car.h"

using namespace std;

class Simulator
{
private:
    Car currentCar = Car();
    int carPosX, carPosY;
    vector<vector<int>> data;
public:
    Simulator(int dimX, int dimY, int startX, int startY, char startF, string command);
    bool Calculate();
    void printMatrix();
};