#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "conway.h"
using namespace std;

bool operator==(const Grid& first, const Grid& second) {
    if (first.num_rows() != second.num_rows() || first.num_cols() != second.num_cols()) {
        return false; 
    }

    for (int row = 0; row < first.num_rows(); row++) {
        for (int col = 0; col < first.num_cols(); col++) {
            if (first.get_cell(row, col).is_on() != second.get_cell(row, col).is_on()) {
                return false;
            }
        }
    }

    return true;
}

TEST_CASE("Glider") {
    Conway game(5, 5); 
    game.grid.get_cell(2, 0).turn_on();
    game.grid.get_cell(3, 1).turn_on();
    game.grid.get_cell(3, 2).turn_on();
    game.grid.get_cell(2, 2).turn_on();
    game.grid.get_cell(1, 2).turn_on();
    game.update_all();

    Grid grid(5, 5);
    grid.get_cell(1, 1).turn_on();
    grid.get_cell(3, 1).turn_on();
    grid.get_cell(3, 2).turn_on();
    grid.get_cell(2, 2).turn_on();
    grid.get_cell(2, 3).turn_on();

    CHECK_EQ(game.grid, grid);

    game.update_all();

    Grid grid2(5, 5);
    grid2.get_cell(3, 1).turn_on();
    grid2.get_cell(3, 2).turn_on();
    grid2.get_cell(3, 3).turn_on();
    grid2.get_cell(2, 3).turn_on();
    grid2.get_cell(1, 2).turn_on();

    CHECK_EQ(game.grid, grid2);

    game.update_all();

    Grid grid3(5, 5);
    grid3.get_cell(2, 1).turn_on();
    grid3.get_cell(3, 2).turn_on();
    grid3.get_cell(4, 2).turn_on();
    grid3.get_cell(3, 3).turn_on();
    grid3.get_cell(2, 3).turn_on();

    CHECK_EQ(game.grid, grid3);

    game.update_all();

    Grid grid4(5, 5);
    grid4.get_cell(3, 1).turn_on();
    grid4.get_cell(4, 2).turn_on();
    grid4.get_cell(4, 3).turn_on();
    grid4.get_cell(3, 3).turn_on();
    grid4.get_cell(2, 3).turn_on();

    CHECK_EQ(game.grid, grid4);
}

TEST_CASE("Stable") {
    Conway game(5, 5); 
    game.grid.get_cell(1, 1).turn_on();
    game.grid.get_cell(1, 2).turn_on();
    game.grid.get_cell(2, 2).turn_on();
    game.grid.get_cell(2, 1).turn_on();
    game.update_all();

    Grid grid(5, 5);
    grid.get_cell(1, 1).turn_on();
    grid.get_cell(1, 2).turn_on();
    grid.get_cell(2, 2).turn_on();
    grid.get_cell(2, 1).turn_on();

    CHECK_EQ(game.grid, grid);
}

TEST_CASE("Oscillator") {
    Conway game(5, 5); 
    game.grid.get_cell(1, 0).turn_on();
    game.grid.get_cell(1, 1).turn_on();
    game.grid.get_cell(1, 2).turn_on();
    game.grid.get_cell(2, 1).turn_on();
    game.grid.get_cell(2, 2).turn_on();
    game.grid.get_cell(2, 3).turn_on();
    game.update_all();

    Grid grid(5, 5);
    grid.get_cell(0, 1).turn_on();
    grid.get_cell(1, 0).turn_on();
    grid.get_cell(2, 0).turn_on();
    grid.get_cell(1, 3).turn_on();
    grid.get_cell(2, 3).turn_on();
    grid.get_cell(3, 2).turn_on();

    CHECK_EQ(game.grid, grid);

    game.update_all();

    Grid grid2(5, 5);
    grid2.get_cell(1, 0).turn_on();
    grid2.get_cell(1, 1).turn_on();
    grid2.get_cell(1, 2).turn_on();
    grid2.get_cell(2, 1).turn_on();
    grid2.get_cell(2, 2).turn_on();
    grid2.get_cell(2, 3).turn_on();

    CHECK_EQ(game.grid, grid2);
}
