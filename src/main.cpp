#include <iostream> //std::cout
#include "../include/Life.h"

int main(){

    //Tests
    Life life(3,3);

     std::vector<position> alive;

    for(int i = 0 ; i < 3; i++){
        for(int j = 0; j < 3; j++){
            position pos;
            pos.rowIndex = i;
            pos.columnIndex = j;
            if (i == 1 || i == 0){
                alive.push_back(pos);
            }
        }
    }

     life.set_alive(alive);

    std::vector<std::vector<Cell>> matrix;
    matrix = life.get_config();


    for(int i = 0 ; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << matrix[i][j].get_alive() << "   ";

        }

        std::cout<< std::endl;
    }

    matrix[1][1].check_neighbors(matrix);

    std::cout<< matrix[1][1].get_alive_neighbors()<< std::endl;

    return 0;
}
