#include "Simulator.h"


Simulator::Simulator(int dimX, int dimY, int startX, int startY, char startF, string command) : data(dimX, std::vector<int>(dimY, 0)){
    currentCar.changeDir(startF);
    data[startX][startY] = 1;
    carPosX = startX;
    carPosY = startY;

}

bool Simulator::Calculate(){}

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
