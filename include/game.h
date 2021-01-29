#ifndef GAME_H
#define GAME_H

#include <vector>
#include <curses.h>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <future>

#include "board_generator.h"

class Game {
public: 
    Game(int r, int c, WINDOW *win, std::unique_ptr<Board_Generator> board) : _row(r-2), _col(c-2), _win(win), _board(std::move(board)) {}
    ~Game() { delwin(_win); }
    void load_game();
    void launch_game();
    void print_inner_board(); // dummy method for test
private:
    std::vector<std::vector<int> > _inner_board;
    int _row;
    int _col;
    int score = 0;
    WINDOW *_win;
    int obstacle_delay;  // inscreases to get higher speed
    int obstacle_max_gap; // gap for vehicle to pass through
    std::unique_ptr<Board_Generator> _board;
    std::mutex _mutex;
    std::condition_variable _cv;
    bool game_should_go_on = true; 
    bool vehicle_created = false; // obstacle generation should wait until player/vehicle is created... this var controls that
    void move_my_vehicle(std::promise<void>&&);
    void generate_obstacle();
    int get_gap_index();
    void change_inner_board_value(int, int, int);
    int get_inner_board_cell(int, int);
    void post_game_over();
    bool check_collision_from_vehicle(int, int);
    bool check_collision_from_obstacle(int, int);
    void stop_game();
    int get_obstacle_delay();
    int get_obstacle_gap();
};

#endif