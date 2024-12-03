#include "cell.h"
#include "ncurses.h"

Cell::Cell(int x, int y) : x(x), y(y) {
    this->state = false;
}

void Cell::draw() const {
    if (is_on()) {
        mvaddch(y, x, '#');
    } else {
        mvaddch(y, x, ' ');
    }
}

bool Cell::is_on() const {
    return state;
}

bool Cell::is_off() const {
    return !is_on();
}

void Cell::turn_on() {
    state = true;
}

void Cell::turn_off() {
    state = false;
}

void Cell::toggle() {
    if (is_on()) {
        turn_off();
    } else {
        turn_on();
    }
}

