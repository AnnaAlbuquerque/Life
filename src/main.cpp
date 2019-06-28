#include <iostream> //std::cout
#include "../include/GameLoop.h"

int main(int argc, char *argv[]){

    //Tests
    GameLoop game;

    game.initialize( argc, argv);
    Life test;

    test = game.get_life();

    std::vector<std::vector<Cell>> matrix;
    matrix = test.get_config();

    for(int i = 0 ; i < test.get_rows(); i++){
        for(int j = 0; j < test.get_columns(); j++){
            std::cout << matrix[i + 1][j + 1].get_alive() << "   ";

        }

        std::cout<< std::endl;
    }

    matrix[1][1].check_neighbors(matrix);

    std::cout<< matrix[2][2].get_alive_neighbors()<< std::endl;

    return 0;
}
