#include "Board.h"

Board::Board() : cur_player_(Player::PLAYER_O), game_status_(GameState::GAME){
	for (int i = 0; i < FIELD_SIZE; i++){
		for (int j = 0; j < FIELD_SIZE; j++){
			field_.fld[i][j] = FieldState::EMPTY;
		}
	}
};

void Board::make_turn(int x, int y, Player pl){
	switch(pl){
		case Player::PLAYER_X: {
			field_.fld[x][y] = FieldState::FIELD_X;
		}
		break;
		case Player::PLAYER_O: {
			field_.fld[x][y] = FieldState::FIELD_O;
		}
		break;
	}
	if (game_status_ == GameState::GAME){
		if (pl == Player::PLAYER_O)
			cur_player_ = Player::PLAYER_X;
		if (pl == Player::PLAYER_X)
			cur_player_ = Player::PLAYER_O;
	}
	return;
};

bool Board::can_make_turn(int x, int y, Player pl){
	if (x > UPPER_BORDER || x < LOWER_BORDER || y > UPPER_BORDER || y < LOWER_BORDER){
		return false;
	}
	if (field_.fld[x][y] != FieldState::EMPTY)
		return false;
	if (this->check_end_game() != GameState::GAME)
		return false;
	return pl == cur_player_;
};

GameState Board::check_line(int start_x, int start_y, int offset_x, int offset_y){
	int O_cnt = 0;
	int X_cnt = 0;
	int cur_x, cur_y;
	for (int i = 0; i < 5; i++){
		O_cnt = 0;
		X_cnt = 0;
		cur_x = start_x + i * offset_x;
		cur_y = start_y + i * offset_y;
		for (int j = 0; j <= 5; j++){
			if (cur_x > UPPER_BORDER || cur_x < LOWER_BORDER || cur_y > UPPER_BORDER || cur_y < LOWER_BORDER)
				break;
			if (field_.fld[cur_x][cur_y] == FieldState::FIELD_O)
				O_cnt++;
			if (field_.fld[cur_x][cur_y] == FieldState::FIELD_X)
				X_cnt++;
			cur_x += offset_x;
			cur_y += offset_y;
		}
		if (O_cnt == 5)
			return GameState::O_WIN;
		if (X_cnt == 5)
			return GameState::X_WIN;
	}
	return GameState::GAME;
};

GameState Board::check_end_game(){

	for (int i = 0; i < FIELD_SIZE; i++){
		if (check_line(0, i, 1, 0) != GameState::GAME)
			game_status_ = check_line(0, i, 1, 0);
		if (check_line(i, 0, 0, 1) != GameState::GAME)
			game_status_ = check_line(i, 0, 0, 1);
		if (check_line(0, i, 1, 1) != GameState::GAME)
			game_status_ = check_line(0, i, 1, 1);
		if (check_line(i, 0, 1, 1) != GameState::GAME)
			game_status_ = check_line(i, 0, 1, 1);
		if (check_line(9, i, -1, 1) != GameState::GAME)
			game_status_ = check_line(9, i, -1, 1);
		if (check_line(9 - i, 0, -1, 1) != GameState::GAME)
			game_status_ = check_line(9 - i, 0, -1, 1);
	}

	// Check draw

	int empty_cnt = 0;

	for (int i = 0; i < FIELD_SIZE; i++)
		for (int j = 0; j < FIELD_SIZE; j++)
			if (field_.fld[i][j] == FieldState::EMPTY)
				empty_cnt++;

	if (empty_cnt == 0 && game_status_ == GameState::GAME)
		game_status_ = GameState::DRAW;

	return game_status_;
};

Player Board::who_play(){
	return cur_player_;
};

const Field& Board::get_field() const{
	return field_;
}