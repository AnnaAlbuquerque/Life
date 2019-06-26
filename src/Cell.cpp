#include "../include/Cell.h"

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GETS

bool Cell::get_alive(){
    return alive;
}

int Cell::get_alive_neighbors(){
    return alive_neighbors;
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SETS

void Cell::set_alive(bool isalive){
    alive = isalive;
}

void Cell::set_position(position pos){
    matrix_position = pos;
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> OTHER FUNCTIONS

void Cell::check_neighbors(std::vector<std::vector<Cell>> matrix){
    //It'll be used to see how many neighbours a cell has
    int count = 0;

    //We need to check 8 neighbors

    /*
    X - current Cell
    ----------------------------
    |        |        |        |
    |  11    |   12   |   13   |
    |        |        |        |
    ----------------------------
    |        |   22   |        |
    |  21    |   X    |  23    |
    |        |        |        |
    ----------------------------
    |        |        |        |
    |   31   |  32    |  33    |
    |        |        |        |
    ----------------------------
     */

    //Checking 11 -> curentI - 1 e currentJ -1
    if(matrix[matrix_position.rowIndex - 1][matrix_position.columnIndex - 1].get_alive()){
        count++;
    }

    //Checking 12 -> curentI - 1
    if(matrix[matrix_position.rowIndex - 1][matrix_position.columnIndex].get_alive()){
        count++;
    }

    //Checking 13 -> curentI - 1 e currentJ +1
    if(matrix[matrix_position.rowIndex - 1][matrix_position.columnIndex + 1].get_alive()){
        count++;
    }

    //Checking 21 -> currentJ -1
    if(matrix[matrix_position.rowIndex][matrix_position.columnIndex - 1].get_alive()){
        count++;
    }

    //Checking 23 ->  currentJ + 1
    if(matrix[matrix_position.rowIndex][matrix_position.columnIndex + 1].get_alive()){
        count++;
    }

    //Checking 31 -> curentI + 1 e currentJ -1
    if(matrix[matrix_position.rowIndex + 1][matrix_position.columnIndex - 1].get_alive()){
        count++;
    }

    //Checking 32 -> curentI + 1 e currentJ
    if(matrix[matrix_position.rowIndex + 1][matrix_position.columnIndex].get_alive()){
        count++;
    }

    //Checking 33 -> curentI + 1 e currentJ + 1
    if(matrix[matrix_position.rowIndex + 1][matrix_position.columnIndex + 1].get_alive()){
        count++;
    }

    alive_neighbors = count;
    
}