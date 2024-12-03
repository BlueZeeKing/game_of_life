#pragma once

struct Cell {
    private:
        const int x;
        const int y;
        bool state;

    public:
        Cell(int x, int y);

        void draw() const;
        bool is_off() const;
        bool is_on() const;
        void turn_off();
        void turn_on();
        void toggle();
};
