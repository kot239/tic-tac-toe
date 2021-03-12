#include "Controller.h"

Controller::Controller(Board &board, BoardView &view) : board_(board), view_(view) {};

Controller::~Controller() {
	delete &board_;
	delete &view_;
};


void Controller::game_loop() {
	int x_ = 0;
	int y_ = 0;
	bool bad_turn = false;
	bool last_move = false;
	while(board_.check_end_game() == GameState::GAME){
		if (bad_turn)
			view_.print_bad_move();
		view_.print_who_play(board_.who_play(), board_.get_field(), last_move, bad_turn);
		view_.read_move(x_, y_, board_.get_field());
		if (x_ == -1 && y_ == -1)
			return;
		if (board_.can_make_turn(x_, y_, board_.who_play())){
			board_.make_turn(x_, y_, board_.who_play());
			bad_turn = false;
		} else {
			bad_turn = true;
		}
	}
	last_move = true;
	view_.print_field(board_.get_field(), last_move);
	view_.print_end_game(board_.check_end_game());
	view_.wait_exit();
	return;
};