#ifndef LIFE_H
#define LIFE_H

#include <vector> //std::vector
#include<iostream> //std::cout
#include <sstream>
#include <iomanip>  // std::setw, std::setfill

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

        //! \brief Print the matrix
        void print_configuration();

        //! \brief Check how many neighbors a specific Cell has
        //! \param two integer first represents cell's row and second cell's column
        void check_neighbors (int i, int j);

        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GETS

        //! \brief Returns a vector of alive cells position
        std::vector<position> get_alive();

        //! \brief Returns a matrix that represents our current configuration
        std::vector<std::vector<Cell>> get_config();

        //! \brief Returns configuration number of rows
        int get_rows();

        //! \brief Returns configuration number of columns
        int get_columns();


        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SETS
                
        //! \brief Set cell alive to true
        //! \param A vector that contains the position of alive cells.
        void set_alive(std::vector<position> vector_position);

        //! \brief Set life number of rows and columns
        //! \param int r - number of rows. int c - number of columns
        void set_rows_columns(int r, int c);




};

#endif