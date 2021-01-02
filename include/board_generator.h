#ifndef BOARD_GENERATOR_H
#define BOARD_GENERATOR_H

#include <vector>
#include <curses.h>
#include <mutex>
#include <memory>

using std::vector;

class Board_Generator {
public:
    Board_Generator(int &l, int &w, WINDOW *win) : _length(l), _width(w), _win(win) {} 
    ~Board_Generator() { delwin(_win); }

    void draw_board();
    void update_cell(int, int, int, int, int); // specially for updating player/vehicle state change
    void update_cell(int, vector<int>&, int); // specially for blocks state change
private:
    unsigned int _length;
    unsigned int _width; 
    WINDOW *_win;
    std::mutex _mutex;
};

#endif