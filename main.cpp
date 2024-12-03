#include "conway.h"
#include <clocale>
#include <ncurses.h>

#define COLOR_NORMAL 1
#define COLOR_HIGHLIGHT 2

int main() {
    // Setup ncurses
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    start_color();
    timeout(-1);
    curs_set(0);

    // Setup the 2 colors that are used
    init_pair(COLOR_NORMAL, COLOR_WHITE, COLOR_BLACK);
    init_pair(COLOR_HIGHLIGHT, COLOR_WHITE, COLOR_RED);
    color_set(COLOR_NORMAL, nullptr);

    // Initialize the current state
    bool running = false;
    int current_row = 0;
    int current_col = 0;

    // Initializes the grid to the size of the screen
    Conway game = Conway(getmaxy(stdscr), getmaxx(stdscr));

    // Draw the blank grid and highlight the cursor position
    game.grid.draw();
    color_set(COLOR_HIGHLIGHT, nullptr);
    game.grid.get_cell(current_row, current_col).draw();
    color_set(COLOR_NORMAL, nullptr);
    refresh();

    // Main loop
    while (true) {
        // Get a character. This blocks when then game is paused and has a timeout of 100ms if the game is running
        int character = getch();

        if (character == 'q') {
            break;
        }

        if (!running) {
            // If the game is paused stop highlighting the current color
            game.grid.get_cell(current_row, current_col).draw();
            
            switch (character) {
            // Move the cursor based on the user input
            case 'w': 
            case 'k': 
                current_row = max(current_row - 1, 0);
                break;
            case 's': 
            case 'j': 
                current_row = min(current_row + 1, game.grid.num_rows() - 1);
                break;
            case 'a': 
            case 'h': 
                current_col = max(current_col - 1, 0);
                break;
            case 'd': 
            case 'l': 
                current_col = min(current_col + 1, game.grid.num_cols() - 1);
                break;
            // Toggle the current cell when space is pressed
            case ' ': 
                game.grid.get_cell(current_row, current_col).toggle();
                break;
            // Resume the game when p is pressed
            case 'p':
                timeout(100);
                running = true;
                break;
            } 

            color_set(COLOR_HIGHLIGHT, nullptr);
            game.grid.get_cell(current_row, current_col).draw();
            color_set(COLOR_NORMAL, nullptr);
        } else {
            // Pause the game when p is pressed
            if (character == 'p') {
                timeout(-1);
                running = false;
            } 

            game.update_all();
            game.grid.draw();
        }

        // Update the display
        refresh();
    }

    // Close ncurses
    endwin();
}
