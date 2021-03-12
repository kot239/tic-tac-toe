#include <ncurses.h>

#include "NcursesBoardView.h"

NcursesBoardView::NcursesBoardView() {
	initscr();
	curs_set(0);
	keypad(stdscr, true);
};

NcursesBoardView::~NcursesBoardView() {
	endwin();
};

void NcursesBoardView::print_field(Field fld, bool end){
	move(0, 0);
	if (end){
		printw("++++++++++++++++++++++++++++\n");
	} else {
		printw("+--------------------------+\n");
	}
	for (int i = 0; i < FIELD_SIZE; i++){
		printw("|        ");
		for (int j = 0; j < FIELD_SIZE; j++){
			switch (fld.fld[j][i]){
				case FieldState::EMPTY: {
					if (j == x_ && i == y_){
						addch('.' | A_STANDOUT);
						continue;
					}
					addch('.');
				}
				break;
				case FieldState::FIELD_X: {
					if (j == x_ && i == y_){
						addch('X' | A_STANDOUT);
						continue;
					}
					addch('X');
				}
				break;
				case FieldState::FIELD_O: {
					if (j == x_ && i == y_){
						addch('O' | A_STANDOUT);
						continue;
					}
					addch('O');
				}
				break;
			}
		}
		printw("        |");
		addch('\n');
	}
};

void NcursesBoardView::print_end_game(GameState gs){
	move(11, 0);
	if (gs == GameState::O_WIN)
		printw("+--------- O wins ---------+");
	if (gs == GameState::X_WIN)
		printw("+--------- X wins ---------+");
	if (gs == GameState::DRAW)
		printw("+---------- Draw ----------+");
};

void NcursesBoardView::print_bad_move(){
	move(11, 0);
	printw("+-------- Bad turn --------+");
};

void NcursesBoardView::print_who_play(Player pl, Field fld, bool end, bool bad_move){
	if (!bad_move)
		print_field(fld, end);
	move(11, 0);
	if (!end){
		char who_player = (pl == Player::PLAYER_O) ? 'O' : 'X';
		printw("+--------- %c move ---------+\n", who_player);
	}
};

void NcursesBoardView::wait_exit(){
	move(12, 0);
	printw("Press F to exit");
	refresh();
	int but;
	bool choise = true; 
	while (choise){
		but = getch();
		if (but == 'f')
			choise = false;
	}
};

void NcursesBoardView::read_move(int &x, int &y, Field fld){
	bool choise = true;
	int but;
	while (choise){
		print_field(fld, false);
		but = getch();
		switch (but){
			case ' ': {
				choise = false;
			}
			break;
			case KEY_UP: {
				if (y_ != LOWER_BORDER)
					y_--;
			}
			break;
			case KEY_DOWN: {
				if (y_ != UPPER_BORDER)
					y_++;
			}
			break;
			case KEY_RIGHT: {
				if (x_ != UPPER_BORDER)
					x_++;
			}
			break;
			case KEY_LEFT: {
				if (x_ != LOWER_BORDER)
					x_--;
			}
			break;
			case 'x': {
				x_ = -1;
				y_ = -1;
				choise = false;
			}
			break;
		}
	}
	x = x_;
	y = y_;
};