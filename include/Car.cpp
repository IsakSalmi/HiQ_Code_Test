#include "Car.h"

Car::Car(){
    forward[0] = 0;
    forward[1] = 0;
    backword[0] = 0;
    backword[1] = 0;
}

void Car::changeDir(char dir){
    direction = dir;
    if(dir == 'N'){
        forward[0] = 0;
        forward[1] = -1;
        backword[0] = 0;
        backword[1] = -1;
    } 
    else if(dir == 'E'){
        forward[0] = 1;
        forward[1] = 0;
        backword[0] = 1;
        backword[1] = 0;
    }
    else if(dir == 'S'){
        forward[0] = 1;
        forward[1] = 0;
        backword[0] = 1;
        backword[1] = 0;
    }
    else if(dir == 'W'){
        forward[0] = -1;
        forward[1] = 0;
        backword[0] = -1;
        backword[1] = 0;
    }
    else{
        cout << "somthing whent wrong" << endl;
    }
}

void Car::printDir(){
    cout << direction << endl;
    cout << forward[0] << forward[1] << endl;
    cout << backword[0] << backword[1] << endl;
}