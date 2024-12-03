#pragma once

#include "cell.h"
#include <vector>
using namespace std;

struct Grid {
    private:
        vector<vector<Cell>> array;
    
    public:
        Grid(int rows, int cols);

        void draw() const;
        int num_rows() const;
        int num_cols() const;
        Cell& get_cell(int row, int col);
        const Cell& get_cell(int row, int col) const;
        bool test_is_alive(int row, int col) const;
};
