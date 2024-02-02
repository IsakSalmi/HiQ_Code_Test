#include "TUI.h"


TUI::TUI(){}

/**
 * @brief This code is responsible for running the main loop and asking for all the parameters and check if all the parameter is ok
 * 
 */
void TUI::mainLoop(){
    do{
        cout << "Enter two positive integers separated by a space (Row Col): ";
        cin >> fieldDimX >> fieldDimY;

        if (cin.fail() || fieldDimX <= 0 || fieldDimY <= 0) { // clear the input if the input was wrong
            cout << "Invalid input. Please enter two positive integers.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (cin.fail() || fieldDimX <= 0 || fieldDimY <= 0);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    do {
        cout << "Enter starting position Row Col direction (in the interval of the room): ";
        cin >> startX >> startY >> direction;

        if (cin.fail() || startX < 0 || startX >= fieldDimX || startY < 0 || startY >= fieldDimY || !(checkDir(direction))) { // clear the input if the input was wrong
            cout << "Invalid input. Please enter valid values.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (cin.fail() || startX < 0 || startX >= fieldDimX || startY < 0 || startY >= fieldDimY || !(checkDir(direction)));
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    do{
        cout << "Enter command(only F B L R): ";
        cin >> command;
    }while(!(checkCommand(command)));

    Simulator test(fieldDimX,fieldDimY,startX,startY,direction,command);//create the simulator with the given input
    test.Calculate();//start the calculation
}

/**
 * @brief check if the given char is one of N E S and W
 * 
 * @param Dir The char that you whant to check
 * @return true if thay are one of N E S W
 * @return false if its not one of N E S W
 */
bool TUI::checkDir(char Dir){
    if((Dir == 'N')||(Dir == 'E')||(Dir == 'S')||(Dir == 'W')){
        return true;
    }
    return false;
}

/**
 * @brief check if a string only contains F B L R
 * 
 * @param command the given string
 * @return true if all the char is one of F B L R
 * @return false if thay are not one of F B L R
 */
bool TUI::checkCommand(string command){
    for(int i = 0; i < command.length(); i++){
        if((command[i] != 'F') && (command[i] != 'B') && (command[i] != 'L') && (command[i] != 'R')){
            return false;
        }
    }
    return true;
}
