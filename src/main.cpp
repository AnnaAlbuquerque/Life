#include <iostream> //std::cout
#include "../include/GameLoop.h"

int main(int argc, char *argv[]){

    //Tests
    GameLoop game;

    game.initialize( argc, argv);
    Life test;

    test = game.get_life();

    std::vector<std::vector<Cell>> matrix;

    test.check_neighbors(1,1);
     matrix = test.get_config();

    std::cout<< matrix[1][1].get_alive_neighbors() << std::endl;

    return 0;
}
