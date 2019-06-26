#include <iostream> //std::cout
#include "../include/Cell.h" 

int main(){

    //Cell tests
    std::vector<std::vector<Cell>> matrix;

    matrix.resize(3);
    for (int i = 0; i < 3; ++i){
        matrix[i].resize(3);
    }
        

    for (int i = 0; i < 3; i++){    
        for(int j = 0; j < 3; j++){
            position pos;
            pos.rowIndex = i;
            pos.columnIndex = j;
            matrix[i][j].set_position(pos);
            matrix[i][j].set_alive(true);
        }
    }

    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std:: cout << matrix[i][j].get_alive() <<"   ";
        }

        std::cout<<std::endl;
    }

    matrix[1][1].check_neighbors(matrix);

    std::cout<< matrix[1][1].get_alive_neighbors();

    return 0;
}
