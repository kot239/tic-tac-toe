#include <iostream>
#include <cstring>

#include "Board.h"
#include "StdioBoardView.h"
#include "NcursesBoardView.h"
#include "Controller.h"

int main(int argc, char* argv[]) {
	GameType type = GameType::FIELD;
	Board *board = new Board;
	BoardView *view;
	if (argc > 1){
		if (strcmp(argv[1], "silent") == 0){
			type = GameType::SILENT;
			view = new StdioBoardView(type);
		} else if (strcmp(argv[1], "curses") == 0){
			view = new NcursesBoardView();
		} else {
			std::cout << "Wrong call of game\n";
			return 0;
		}
	} else {
		view = new StdioBoardView(type);
	}
	Controller *game = new Controller(*board, *view);
	game->game_loop();
	delete game;
	return 0;
}