#include "Simulator.h"

/**
 * @brief Construct a new Simulator:: Simulator object
 * 
 * @param dimX is the dimensions in X
 * @param dimY is the dimensions in Y
 * @param startX is the start X for the car
 * @param startY is the start X for the car
 * @param startF is the starting direction for the car (must be one of N W E S)
 * @param command is a string of only F B L R
 */
Simulator::Simulator(int dimX, int dimY, int startX, int startY, char startF, string command) : data(dimX, std::vector<int>(dimY, 0)){
    currentCar.changeDir(startF);
    carPosX = dimX - startX - 1;
    carPosY = startY;
    data[carPosX][carPosY] = 1;

    maxPosX = dimX;
    maxPosY = dimY;
    newCommand = command;

}

/**
 * @brief Main calculation of the simulation. It calculate if the car can execute the command
 * 
 * @return true if it was successful 
 * @return false if it was not successful 
 */
bool Simulator::Calculate(){
    int *forwardMove;
    int* backMove;
    bool haveNotCrash = true;
    for(int i = 0; i < newCommand.length(); i++){
        printMatrix();
        if(newCommand[i] == 'F'){
            forwardMove = currentCar.getForward(); //get the array for the x and y directions
            haveNotCrash = moveCar(carPosX, carPosY, carPosX + forwardMove[0], carPosY + forwardMove[1]);
            if(haveNotCrash == false){ // if we crashed when moving the car
                cout << "car crashed on: " << maxPosX - carPosX - 1 << " " << carPosY << " trying to go to: " << maxPosX - carPosX + forwardMove[0] - 1 << " " << carPosY + forwardMove[1] << endl;
                break;
            }
        }
        else if(newCommand[i] == 'B'){
            backMove = currentCar.getBackward();//get the array for the x and y directions
            haveNotCrash = moveCar(carPosX, carPosY, carPosX + backMove[0], carPosY + backMove[1]);
            if(haveNotCrash == false){ // if we crashed when moving the car
                cout << "car crashed on: " << maxPosX - carPosX - 1 << " " << carPosY << " trying to go to: " << maxPosX - carPosX + backMove[0] - 1 << " " << carPosY + backMove[1] << endl;
                break;
            }
        }
        else if(newCommand[i] == 'L'){
            currentCar.turnCar('L');
        }
        else if(newCommand[i] == 'R'){
            currentCar.turnCar('R');
        }
        else{
            cout << "somthing whent wrong with the simulation" << endl;
        }
    }
    printMatrix();
    if(haveNotCrash == true){
        cout << "the route was successful and the car ended on: "<< maxPosX - carPosX - 1 << ":" << carPosY << endl;
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief Move the car from a start x and y to a end x and y in the room
 * 
 * @param startX the cars start x value
 * @param startY the cars start y value
 * @param endX the cars end x value
 * @param endY the cars end y value
 * @return true if the move was successful  
 * @return false if the move was not successful 
 */
bool Simulator::moveCar(int startX, int startY, int endX, int endY){
    if((endX >= maxPosX) || (endY >= maxPosY) || (endX < 0) || (endY < 0)){
        return false;
    }
    data[startX][startY] = 0;
    data[endX][endY] = 1;
    carPosX = endX;
    carPosY = endY;
    return true;
}

/**
 * @brief print the matrix of the room. 0 is a empty space and 1 is a car.
 * 
 */
void Simulator::printMatrix(){
    for (const auto& row : data)
    {
        for (int value : row)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    cout << "\n";
}
