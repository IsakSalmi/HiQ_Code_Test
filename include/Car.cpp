#include "Car.h"

Car::Car(){
    forward[0] = 0;
    forward[1] = 0;
    backward[0] = 0;
    backward[1] = 0;
}

int* Car::getForward(){return forward;}
int* Car::getBackward(){return backward;}

void Car::changeDir(char dir){
    direction = dir;
    if(dir == 'N'){
        forward[0] = 0;
        forward[1] = -1;
        backward[0] = 0;
        backward[1] = 1;
    } 
    else if(dir == 'E'){
        forward[0] = 1;
        forward[1] = 0;
        backward[0] = -1;
        backward[1] = 0;
    }
    else if(dir == 'S'){
        forward[0] = 0;
        forward[1] = 1;
        backward[0] = 0;
        backward[1] = -1;
    }
    else if(dir == 'W'){
        forward[0] = -1;
        forward[1] = 0;
        backward[0] = 1;
        backward[1] = 0;
    }
    else{
        cout << "somthing whent wrong" << endl;
    }
}

void Car::printDir(){
    cout << direction << endl;
    cout << forward[0] << ":" << forward[1] << endl;
    cout << backward[0] << ":" << backward[1] << endl;
}