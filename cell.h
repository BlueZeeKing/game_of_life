#pragma once

struct Cell {
    private:
        const int x;
        const int y;
        bool state;

    public:
        Cell(int x, int y);

        void draw();
        bool is_off();
        bool is_on();
        void turn_off();
        void turn_on();
        void toggle();
};
