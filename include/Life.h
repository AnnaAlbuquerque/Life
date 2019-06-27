#ifndef LIFE_H
#define LIFE_H

#include <vector>
#include "Cell.h"

class Life{
    private:
        std::vector<std::vector<Cell>> Config; //Current configuration
        int rows, columns; // width and heigh of the configuration
        std::vector<std::vector<Cell>> Log; // It will save only alive Cells 
        std::vector<position> alive_cells; //A vector of position of those cells that are current alive

    public:
        //! \brief Life Constructors
        Life(){};
        Life(int nRow, int nCol);

        //! \brief Destructor
        ~Life(){}

        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GETS

        //! \brief Returns a vector of alive cells position
        std::vector<position> get_alive();

        //! \brief Returns a matrix that represents our current configuration
        std::vector<std::vector<Cell>> get_config();


        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SETS
        
        //! \brief Set cell alive to true
        //! \param A vector that contains the position of alive cells.
        void set_alive(std::vector<position> vector_position);




};

#endif