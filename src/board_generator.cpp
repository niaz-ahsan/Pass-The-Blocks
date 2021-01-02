#include <iostream>

#include <board_generator.h>
#include <game.h>

using std::vector;

void Board_Generator::draw_board() {
    clear();
    for(int row = 0; row < _length; row++) {
        mvwprintw(_win, row, 0, "|");
        for(int col = 1; col <= _width-2; col++) {
            if(row == 0 || row == _length-1) {
                mvwprintw(_win, row, col, "=");
            } else {     
                mvwprintw(_win, row, col, " ");
            }
        }  
        mvwprintw(_win, row, _width-1, "|\n");
    }
    printw("*  = Player\n");
    printw("-  = Incoming blocks\n");
    printw("Use ARROW KEYs to avoid block and up your score\n");
    wrefresh(_win);
}

void Board_Generator::update_cell(int row, int col, int val, int prev_row, int prev_col) {
    mvwprintw(_win, row+1, col+1, "*");
    mvwprintw(_win, prev_row+1, prev_col+1, " ");
    wrefresh(_win); 
}

void Board_Generator::update_cell(int row, vector<int> &cols, int val) {
    for(int i=0; i<cols.size(); i++) {
        if(row > 0) { // preventing change when modifying 1st row
            mvwprintw(_win, row, cols[i]+1, " ");    
        }
        if(row+1 < _length-1) { // preventing modifying board border
            mvwprintw(_win, row+1, cols[i]+1, "-");
        }       
    }
    wrefresh(_win);
}