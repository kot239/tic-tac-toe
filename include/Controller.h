#ifndef HW02_CONTROLLER_H_INCLUDED
#define HW02_CONTROLLER_H_INCLUDED
#include "Board.h"
#include "StdioBoardView.h"

class Controller {
public:
	Controller(Board &board, BoardView &view);
	~Controller();
	void game_loop();

private:
	Board &board_;
	BoardView &view_;
};
#endif