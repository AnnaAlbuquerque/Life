#ifndef CELL_H
#define CELL_H

#include "BasicStructures.h"
#include <vector>

class Cell{
    private:
        bool alive; //true if the cell is alive, false otherwise
        position matrix_position; //position of the cell on the matrix
        int alive_neighbors; //how many alive neighbors the cell has

    public:

        //! \brief Cell Constructors
        Cell(){};
        Cell(position pos){
            matrix_position = pos;
        };

        //! \brief Cell Destructor
        ~Cell(){};

        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GETS

        //! \brief Returns true if the cell is alive
        bool get_alive();

        //! \brief Return how many alive neighbors teh cell has
        int get_alive_neighbors();

        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SETS

        //! \brief Set variable alive to the parameter
        //! \param A boolean. It's true if we want to set a cell alive and false otherwise.
        void set_alive(bool isalive);

        //! \brief Set variable matrix_position to the parameter
        //! \param A position, that contains rowIndex to the matrix row and columnIndex to the matrix column.
        void set_position(position pos);

        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> OTHER FUNCTIONS

        //! \brief Check how many neighbors are alive
        //! \param a matrix of cells that represents a configuration
        void check_neighbors (std::vector<std::vector<Cell>> matrix);
        
};

#endif