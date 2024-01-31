#include "Simulator.h"


Simulator::Simulator(int dimX, int dimY, int startX, int startY, char startF, string command) : data(dimX, std::vector<int>(dimY, 0)){
    currentCar.changeDir(startF);
    data[startY][startX] = 1;
    carPosX = startX;
    carPosY = startY;

    maxPosX = dimX;
    maxPosY = dimY;
    newCommand = command;

}

bool Simulator::Calculate(){
    int *forwardMove;
    int* backMove;
    for(int i = 0; i < newCommand.length(); i++){
        if(newCommand[i] == 'F'){
            forwardMove = currentCar.getForward();
            moveCar(carPosX, carPosY, carPosX + forwardMove[0], carPosY + forwardMove[1]);
        }
        else if(newCommand[i] == 'B'){
            backMove = currentCar.getForward();
            moveCar(carPosX, carPosY, carPosX + backMove[0], carPosY + backMove[1]);
        }
        printMatrix();
    }
    return true;
}

bool Simulator::moveCar(int startX, int startY, int endX, int endY){
    if(endX >= maxPosX && endY >= maxPosY){
        return false;
    }
    data[startY][startX] = 0;
    data[endY][endX] = 1;
    return true;
}

void Simulator::printMatrix(){
    for (const auto& row : data)
    {
        for (int value : row)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    currentCar.printDir();
}
