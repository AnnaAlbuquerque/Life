#include "../include/Life.h"

Life::Life(int nRow, int nCol){
    //Adding 2 to create the safe zone at the borders
    rows = nRow + 2; 
    columns = nCol + 2;

    //Resizing Matrix
    Config.resize(rows);
    for(int i = 0; i < columns; i++){
        Config[i].resize(columns);
    }

    //Setting cells position, and alive to false (at first they're all dead)
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){

            //setting cell variable alive to false
            Config[i][j].set_alive(false);
        }
    }
}

void Life::print_configuration(){
     std::ostringstream data;

        std::cout << "[" << get_rows() << " x " << get_columns() << "]\n" << std::endl;
        for (int i = 0; i < get_rows(); i++) {
                if (i < 10) {
                        data << "[" << i << "]" << std::setw(2) << " ";
                } else {
                        data << "[" << i << "]" << std::setw(1) << " ";
                }

                for (int j = 0; j < get_columns(); j++) {
                        data << std::setw(1) << Config[i][j].get_alive() << " ";
                }
                data << '\n';
        }

        std::cout << data.str() << std::endl;
}

void Life::check_neighbors(int i, int j){
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
    if(Config[i - 1][j - 1].get_alive()){
        count++;
    }

    //Checking 12 -> curentI - 1
    if(Config[i - 1][j].get_alive()){
        count++;
    }

    //Checking 13 -> curentI - 1 e currentJ +1
    if(Config[i - 1][j + 1].get_alive()){
        count++;
    }

    //Checking 21 -> currentJ -1
    if(Config[i][j - 1].get_alive()){
        count++;
    }

    //Checking 23 ->  currentJ + 1
    if(Config[i][j + 1].get_alive()){
        count++;
    }

    //Checking 31 -> curentI + 1 e currentJ -1
    if(Config[i + 1][j - 1].get_alive()){
        count++;
    }

    //Checking 32 -> curentI + 1 e currentJ
    if(Config[i + 1][j].get_alive()){
        count++;
    }

    //Checking 33 -> curentI + 1 e currentJ + 1
    if(Config[i+ 1][j + 1].get_alive()){
        count++;
    }

    Config[i][j].set_alive_neighbors(count);    
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GETS

std::vector<position> Life::get_alive(){
    return alive_cells;
}

std::vector<std::vector<Cell>> Life::get_config(){
    return Config;
}

int Life::get_rows(){
    return rows;
}

int Life::get_columns(){
    return columns ;
}



// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SETS

void Life::set_alive(std::vector<position> vector_position){
    for (auto const& value: vector_position){
        Config[value.rowIndex][value.columnIndex].set_alive(true);
    }
}

void Life::set_rows_columns(int r, int c){
    //Adding 2 to create safe zone
    rows = r + 2;
    columns = c + 2; 

    //Resizing Matrix
    Config.resize(rows);
    for(int i = 0; i < columns; i++){
        Config[i].resize(columns);
    }

    //Setting cells position, and alive to false (at first they're all dead)
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){

            //setting cell variable alive to false
            Config[i][j].set_alive(false);
        }
    }
}