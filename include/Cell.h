#ifndef CELL_H
#define CELL_H

#include "BasicStructures.h"
#include <vector> //std::vector

class Cell{
    private:
        bool alive; //true if the cell is alive, false otherwise
        int alive_neighbors; //how many alive neighbors the cell has

    public:

        //! \brief Cell Constructors
        Cell(){};

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

        //! \brief Set variable alive_neighbors to the parameter
        //! \param a integer that represents how many alive neighbors the cell has
        void set_alive_neighbors(int qnt);
        
};

#endif