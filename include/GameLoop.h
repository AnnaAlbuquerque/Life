#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <string> //std::string
#include <getopt.h> //getopt()
#include <iostream> //std::cout, std::cin, std::cerr
#include <cstdlib> //atoi() - converts string to int
#include <sstream> //std::ostringstream
#include <fstream> //Stream class to read and write from/to files - using std::ifstream


#include "Life.h"

class GameLoop{
    private: 
        Life life; // this will be our configuration + loogs
        char alive_char;
        std::vector<std::vector<position>> log; // It will be used to safe all configurations. It will save only the positions of alive cells.
        int number_configuration = 0; //It will save the number of configurations that happened

        struct user_options{ //will safe all the options that the user choose via command line argument
            std::string imgdir; // Specify directory where output images are written to
            int maxgen; //Maximum number of generations to simulate
            int fps = 1; //Number of generations presented per second
            int blocksize = 5; //Pixel size of a cell. Default = 5.
            std::string bkgcolor; //Color name for the background. Default GREEN.
            std::string alivecolor;  //Color name for representing alive cells. Default RED.
            std::string outfile; //Write the text representation of the simulation to the given filename.
            std::string inputfile; //Name of input file
        }options;

    public:
        //! \brief Constructor
        GameLoop(){};

        //! \brief Destructor
        ~GameLoop(){};

        //! \brief Used when the game is initialized. It'll read file, get user options and start the hole configuration
        void initialize(int argc, char *argv[]);

        //! \brief Used to read user options, returns -1 when an error occurs and 0 otherwise.
        int read_options (int argc, char *argv[]);

        //! \brief Used to read file with inital configuration
        void read_file();

        //! \brief It'll return true, if the Game is over
        bool GameOver();

        //! \brief This class is used to apply the rules
        void process_events();

        //! \brief Responsible for the front-end, it will generate the images
        void render();

        //! \brief Verifies if a configuration is extint, returns true if it is.
        bool extint(); 

        //! \brief Verifies if a configuration is stable, return true if it is.
        bool stable();

        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GETS
        
        //! \brief Get Life - tests purposes
        Life get_life();

        //! \brief Returns char used to alive cells
        char get_alive_char();

        //! \brief Return fps
        int get_fps();

        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SETS

        //! \brief Set char for alive cells
        void set_alive_char(char c);


        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> OUTPUT
        void help_msg();
        void init_msg();

};

#endif