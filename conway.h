#pragma once
#include "grid.h"

struct Conway {
    private:
        vector<vector<int>> count_all_neighbors();
        int count_neighbors(int row, int col);

        static void update_cell(Cell& cell, int num_alive_neighbors);

    public:
        Grid grid;

        Conway(int rows, int cols);
        void update_all();
};
