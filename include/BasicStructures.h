
struct position{
    int rowIndex, columnIndex;

    bool operator==(const position& pos) {
                return ((rowIndex == pos.rowIndex) && (columnIndex == pos.columnIndex));
        }
};

