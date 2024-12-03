#include "conway.h"
#include "grid.h"

Conway::Conway(int rows, int cols): grid(Grid(rows, cols)) { }

void Conway::update_all() {
    vector<vector<int>> neighbor_counts = count_all_neighbors();

    for (int row = 0; row < grid.num_rows(); row++) {
        for (int col = 0; col < grid.num_cols(); col++) {
            Conway::update_cell(grid.get_cell(row, col), neighbor_counts[row][col]);
        }
    }
}

int Conway::count_neighbors(int row, int col) {
    int count = 0;

    count += grid.test_is_alive(row - 1, col - 1);
    count += grid.test_is_alive(row - 1, col);
    count += grid.test_is_alive(row - 1, col + 1);
    count += grid.test_is_alive(row, col - 1);
    count += grid.test_is_alive(row, col + 1);
    count += grid.test_is_alive(row + 1, col - 1);
    count += grid.test_is_alive(row + 1, col);
    count += grid.test_is_alive(row + 1, col + 1);

    return count;
}

vector<vector<int>> Conway::count_all_neighbors() {
    vector<vector<int>> neighbor_counts = vector<vector<int>>();
    neighbor_counts.reserve(grid.num_rows());

    for (int row = 0; row < grid.num_rows(); row++) {
        vector<int> row_counts = vector<int>(); 
        row_counts.reserve(grid.num_cols());

        for (int col = 0; col < grid.num_cols(); col++) {
            int count = count_neighbors(row, col);

            row_counts.push_back(count);
        }

        neighbor_counts.push_back(row_counts);
    }

    return neighbor_counts;
}

void Conway::update_cell(Cell &cell, int num_alive_neighbors) {
    if (cell.is_on() && (num_alive_neighbors < 2 || num_alive_neighbors > 3)) {
        cell.turn_off();
    } else if (cell.is_off() && num_alive_neighbors == 3) {
        cell.turn_on();
    }
}
