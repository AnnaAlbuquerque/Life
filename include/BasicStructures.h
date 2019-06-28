#ifndef BASICSTRUCTURES_H
#define BASICSTRUCTURES_H

struct position{
    int rowIndex, columnIndex;

    bool operator==(const position& pos) {
                return ((rowIndex == pos.rowIndex) && (columnIndex == pos.columnIndex));
        }
};

#endif
