#ifndef HW02_BOARD_H_INCLUDED
#define HW02_BOARD_H_INCLUDED

enum class Player {PLAYER_X, PLAYER_O};
enum class FieldState {EMPTY, FIELD_X, FIELD_O};
enum class GameState {GAME, DRAW, X_WIN, O_WIN};

const int FIELD_SIZE = 10;
const int LOWER_BORDER = 0;
const int UPPER_BORDER = 9;

struct Field {
	FieldState fld[FIELD_SIZE][FIELD_SIZE];
};

class Board {
public:
	Board();
	~Board() = default;

	bool can_make_turn (int x, int y, Player pl);
	void make_turn (int x, int y, Player pl);
	GameState check_line(int start_x, int start_y, int offset_x, int offset_y);
	GameState check_end_game();
	Player who_play();
	
	const Field& get_field() const;
private:
	Player cur_player_;
	GameState game_status_;
	Field field_;
};

#endif