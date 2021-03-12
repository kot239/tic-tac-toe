#ifndef HW02_BOARD_TEST_H_INCLUDED
#define HW02_BOARD_TEST_H_INCLUDED

#include "Board.h"
#include "Test.h"

class BoardTest : public Test {
private:
	void test_not_end_game();
	void test_O_wins();
	void test_X_wins();
	void test_bad_turns();
	void test_vertical_win();
	void test_horizontal_win();
	void test_main_diagonal_win();
	void test_side_diagonal_win();
	void test_draw();
	void test_cur_player();
	void test_game_state();
public:
	void runAllTests() override;
};

#endif