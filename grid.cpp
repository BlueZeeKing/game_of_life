#include "grid.h"
#include "cell.h"
#include <ncurses.h>
#include <vector>

Grid::Grid(int rows, int cols) {
    array = vector<vector<Cell>>();
    array.reserve(rows);

    for (int row = 0; row < rows; row++) {
        array.push_back(vector<Cell>());
        array[row].reserve(cols);

        for (int col = 0; col < cols; col++) {
            array[row].push_back(Cell(col, row));
        }
    }
}

void Grid::draw() const {
    for (int row = 0; row < array.size(); row++) {
        for (int col = 0; col < array[row].size(); col++) {
            get_cell(row, col).draw();
        }
    }
}

int Grid::num_rows() const {
    return array.size();
}

int Grid::num_cols() const {
    return array[0].size();
}

Cell& Grid::get_cell(int row, int col) {
    return array[row][col];
}

const Cell& Grid::get_cell(int row, int col) const {
    return array[row][col];
}

bool Grid::test_is_alive(int row, int col) const {
    return row >= 0 && row < num_rows() && col >= 0 && col < num_cols() && get_cell(row, col).is_on();
}

