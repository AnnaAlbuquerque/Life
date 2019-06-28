#ifndef CELL_H
#define CELL_H

#include "BasicStructures.h"
#include <vector> //std::vector

class Cell{
    private:
        bool alive; //true if the cell is alive, false otherwise

    public:

        //! \brief Cell Constructors
        Cell(){};

        //! \brief Cell Destructor
        ~Cell(){};

        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GETS

        //! \brief Returns true if the cell is alive
        bool get_alive();

        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SETS

        //! \brief Set variable alive to the parameter
        //! \param A boolean. It's true if we want to set a cell alive and false otherwise.
        void set_alive(bool isalive);

};

#endif