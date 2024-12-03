#pragma once

#include "cell.h"
#include <vector>
using namespace std;

struct Grid {
    private:
        vector<vector<Cell>> array;
    
    public:
        Grid(int rows, int cols);

        void draw();
        int num_rows();
        int num_cols();
        Cell& get_cell(int row, int col);
        bool test_is_alive(int row, int col);
};
