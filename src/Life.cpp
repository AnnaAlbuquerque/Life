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
            //setting a auxiliar position
            position pos;
            pos.rowIndex = i;
            pos.columnIndex = j;

            //setting cell variable position
            Config[i][j].set_position(pos);

            //setting cell variable alive to false
            Config[i][j].set_alive(false);
        }
    }
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GETS

std::vector<position> Life::get_alive(){
    return alive_cells;
}

 std::vector<std::vector<Cell>> Life::get_config(){
     return Config;
 }


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SETS

void Life::set_alive(std::vector<position> vector_position){
    for (auto const& value: vector_position){
        Config[value.rowIndex][value.columnIndex].set_alive(true);
    }
}