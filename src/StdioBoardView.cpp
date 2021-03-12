#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <iterator>

#include "StdioBoardView.h"
#include "Board.h"

//const int buf_size = 200;

bool check_number(std::string& s){
	std::string temp = s;
	size_t num = s.size();
	for (size_t i = 0; i < num; i++){
		if (!temp.find_first_not_of("0123456789-"))
			return false;
		temp.erase(0,1);
	}
	return true;
};

BoardView::BoardView() {};

BoardView::~BoardView() {};

StdioBoardView::StdioBoardView(GameType game_type) : game_type_(game_type) {};

void StdioBoardView::print_field(Field fld, bool end){
	if (game_type_ == GameType::FIELD || end){
		std::cout << "\n";
		for (int i = 0; i < FIELD_SIZE; i++){
			for (int j = 0; j < FIELD_SIZE; j++){
				switch (fld.fld[i][j]){
					case FieldState::EMPTY: {
						std::cout << ".";
					}
					break;
					case FieldState::FIELD_X: {
						std::cout << "X";
					}
					break;
					case FieldState::FIELD_O: {
						std::cout << "O";
					}
					break;
				}
			}
			std::cout << "\n";
		}
	}
};

void StdioBoardView::read_move(int &x, int &y, Field fld){
	if (fld.fld[0][0] == FieldState::EMPTY || fld.fld[0][0] == FieldState::FIELD_X || fld.fld[0][0] == FieldState::FIELD_O){
		x = -2;
		y = -2;
	}
	std::string line;
	std::getline(std::cin, line);
	std::istringstream str(line);
	std::vector<std::string> tokens;
	std::copy(std::istream_iterator<std::string>(str), std::istream_iterator<std::string>{}, std::back_inserter(tokens));
	if (tokens.size() == 2 && check_number(tokens[0]) && check_number(tokens[1])){
		x = stoi(tokens[0]);
		y = stoi(tokens[1]);
	}
};

void StdioBoardView::print_bad_move(){
	std::cout << "Bad move!\n";
	return;
};

void StdioBoardView::print_who_play(Player pl, Field fld, bool end, bool bad_move){
	if (!bad_move)
		print_field(fld, end);
	std::string who_player = (pl == Player::PLAYER_O) ? "O" : "X";
	std::cout << who_player << " move: ";
	return;
};

void StdioBoardView::print_end_game(GameState gs){
	if (gs == GameState::O_WIN)
		std::cout << "O wins!\n";
	if (gs == GameState::X_WIN)
		std::cout << "X wins!\n";
	if (gs == GameState::DRAW)
		std::cout << "Draw.\n";
	return;
};

void StdioBoardView::wait_exit(){
	return;
}