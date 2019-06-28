#include <unistd.h>  // usleep()
#include "../include/GameLoop.h"

int main(int argc, char *argv[]){
    //creating a GameLoop
    GameLoop game;

    game.initialize(argc,argv);

    while(!game.GameOver()){
        game.process_events(); // processa os eventos
        game.render();
        usleep(game.get_fps() * 1000000);
    }
}
