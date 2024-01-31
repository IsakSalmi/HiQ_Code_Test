#pragma once

#include <iostream>
#include<tuple>

using namespace std;


class Car
{
private:
    char direction;
    int forward[2];
    int backward[2];
public:
    Car();

    void changeDir(char dir);
    void printDir();
    int* getForward();
    int* getBackward();
};