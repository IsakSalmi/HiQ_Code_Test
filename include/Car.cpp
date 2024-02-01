#include "Car.h"


/**
 * @brief Construct a new Car:: Car object
 * 
 */
Car::Car(){
    forward[0] = 0;
    forward[1] = 0;
    backward[0] = 0;
    backward[1] = 0;
}

/**
 * @brief return the forward array
 * 
 * @return int* consist of 2 variable int[2]
 */
int* Car::getForward(){return forward;}

/**
 * @brief return the backward array
 * 
 * @return int* consist of 2 variable int[2]
 */
int* Car::getBackward(){return backward;}

/**
 * @brief Change the direction of the car and with that also change the forward and backward variables
 * 
 * @param dir is the diraction to change can only be N E S W
 */
void Car::changeDir(char dir){
    direction = dir;
    if(dir == 'N'){
        forward[0] = -1;
        forward[1] = 0;
        backward[0] = 1;
        backward[1] = 0;
    } 
    else if(dir == 'E'){
        forward[0] = 0;
        forward[1] = 1;
        backward[0] = 0;
        backward[1] = -1;
    }
    else if(dir == 'S'){
        forward[0] = 1;
        forward[1] = 0;
        backward[0] = -1;
        backward[1] = 0;
    }
    else if(dir == 'W'){
        forward[0] = 0;
        forward[1] = -1;
        backward[0] = 0;
        backward[1] = 1;
    }
    else{
        cout << "somthing whent wrong" << endl;
    }
}

/**
 * @brief Turn the car left or right by sending in L or R
 * 
 * @param dir can only be L or R
 */
void Car::turnCar(char dir){
    if(dir == 'L'){
        switch (direction)
        {
        case 'N':
            changeDir('W');
            break;
        case 'E':
            changeDir('N');
            break;
        case 'S':
            changeDir('E');
            break;
        case 'W':
            changeDir('S');
            break;
        default:
            cout << "somthing whent wrong with turning" << endl;
            break;
        }
    }
    else if(dir == 'R'){
        switch (direction)
        {
        case 'N':
            changeDir('E');
            break;
        case 'E':
            changeDir('S');
            break;
        case 'S':
            changeDir('W');
            break;
        case 'W':
            changeDir('N');
            break;
        default:
            cout << "somthing whent wrong with turning" << endl;
            break;
        }
    }
}

/**
 * @brief prints out the direction of the car
 * 
 */
void Car::printDir(){
    cout << direction << endl;
    cout << forward[0] << ":" << forward[1] << endl;
    cout << backward[0] << ":" << backward[1] << endl;
}