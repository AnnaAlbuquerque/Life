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

void Cell::set_alive_neighbors(int qnt){
    alive_neighbors = qnt;
}
