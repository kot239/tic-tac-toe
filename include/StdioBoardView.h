#ifndef HW02_STDIO_BOARD_BIEW_H_INCLUDED
#define HW02_STDIO_BOARD_BIEW_H_INCLUDED

#include <string>

#include "Board.h"

enum class GameType {FIELD, SILENT};

bool check_number(std::string& s);

class BoardView {
public:
	BoardView();
	virtual ~BoardView();

	virtual void print_field(Field fld, bool end) = 0;
	virtual void print_end_game(GameState gs) = 0;
	virtual void print_bad_move() = 0;
	virtual void print_who_play(Player pl, Field fld, bool end, bool bad_move) = 0;
	virtual void wait_exit() = 0;
	virtual void read_move(int &x, int &y, Field fld) = 0;
};

class StdioBoardView : public BoardView {
public:
	StdioBoardView(GameType game_type);

	void print_field(Field fld, bool end) override;
	void print_end_game(GameState gs) override;
	void print_bad_move() override;
	void print_who_play(Player pl, Field fld, bool end, bool bad_move) override;
	void read_move(int &x, int &y, Field fld) override;
	void check_input(int &x, int &y);
	void wait_exit() override;
private:
	GameType game_type_;
};

#endif