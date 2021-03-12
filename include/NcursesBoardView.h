#ifndef HW02_NCURSES_BOARD_VIEW_H_INCLUDED
#define HW02_NCURSES_BOARD_VIEW_H_INCLUDED

#include <ncurses.h>

#include "Board.h"
#include "StdioBoardView.h"
#include "Controller.h"

class NcursesBoardView : public BoardView {
public:
	NcursesBoardView();
	~NcursesBoardView();

	void print_field(Field fld, bool end) override;
	void print_end_game(GameState gs) override;
	void print_bad_move() override;
	void print_who_play(Player pl, Field fld, bool end, bool bad_move) override;
	void wait_exit() override;
	void read_move(int &x, int &y, Field fld) override;
private:
	int x_ = 0;
	int y_ = 0;
};

#endif