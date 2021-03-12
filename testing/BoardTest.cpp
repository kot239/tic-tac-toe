#include "Test.h"
#include "BoardTest.h"
#include "Board.h"

void BoardTest::test_not_end_game() {
	Board b;
	b.make_turn(0, 1, Player::PLAYER_O);
	b.make_turn(1, 0, Player::PLAYER_X);
	DO_CHECK(b.check_end_game() == GameState::GAME);
};

void BoardTest::test_O_wins() {
	Board b;
	b.make_turn(0, 0, Player::PLAYER_O);
	b.make_turn(1, 0, Player::PLAYER_X);
	b.make_turn(0, 1, Player::PLAYER_O);
	b.make_turn(1, 1, Player::PLAYER_X);
	b.make_turn(0, 2, Player::PLAYER_O);
	b.make_turn(1, 2, Player::PLAYER_X);
	b.make_turn(0, 3, Player::PLAYER_O);
	b.make_turn(1, 3, Player::PLAYER_X);
	b.make_turn(0, 4, Player::PLAYER_O);
	DO_CHECK(b.check_end_game() == GameState::O_WIN);
};

void BoardTest::test_X_wins() {
	Board b;
	b.make_turn(0, 0, Player::PLAYER_O);
	b.make_turn(0, 9, Player::PLAYER_X);
	b.make_turn(1, 1, Player::PLAYER_O);
	b.make_turn(1, 8, Player::PLAYER_X);
	b.make_turn(9, 9, Player::PLAYER_O);
	b.make_turn(2, 7, Player::PLAYER_X);
	b.make_turn(7, 3, Player::PLAYER_O);
	b.make_turn(3, 6, Player::PLAYER_X);
	b.make_turn(0, 4, Player::PLAYER_O);
	b.make_turn(4, 5, Player::PLAYER_X);
	DO_CHECK(b.check_end_game() == GameState::X_WIN);
};

void BoardTest::test_bad_turns() {
	Board b;
	DO_CHECK(!b.can_make_turn(-1, -1, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(-1, 0, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(-1, 1, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(-1, 2, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(-1, 3, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(-1, 4, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(-1, 5, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(-1, 6, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(-1, 7, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(-1, 8, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(-1, 9, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(-1, 10, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(0, 10, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(1, 10, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(2, 10, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(3, 10, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(4, 10, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(5, 10, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(6, 10, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(7, 10, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(8, 10, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(9, 10, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(10, 10, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(10, -1, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(10, 0, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(10, 1, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(10, 2, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(10, 3, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(10, 4, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(10, 5, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(10, 6, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(10, 7, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(10, 8, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(10, 9, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(0, -1, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(1, -1, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(2, -1, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(3, -1, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(4, -1, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(5, -1, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(6, -1, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(7, -1, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(8, -1, Player::PLAYER_O));
	DO_CHECK(!b.can_make_turn(9, -1, Player::PLAYER_O));
};

void BoardTest::test_vertical_win() {
	Board b, b2, b3;
	b.make_turn(4, 3, Player::PLAYER_O);
	b.make_turn(1, 0, Player::PLAYER_X);
	b.make_turn(5, 3, Player::PLAYER_O);
	b.make_turn(1, 1, Player::PLAYER_X);
	b.make_turn(6, 3, Player::PLAYER_O);
	b.make_turn(1, 2, Player::PLAYER_X);
	b.make_turn(7, 3, Player::PLAYER_O);
	b.make_turn(1, 3, Player::PLAYER_X);
	b.make_turn(8, 3, Player::PLAYER_O);
	DO_CHECK(b.check_end_game() == GameState::O_WIN);

	b2.make_turn(2, 7, Player::PLAYER_O);
	b2.make_turn(2, 4, Player::PLAYER_X);
	b2.make_turn(3, 7, Player::PLAYER_O);
	b2.make_turn(3, 4, Player::PLAYER_X);
	b2.make_turn(4, 7, Player::PLAYER_O);
	b2.make_turn(4, 4, Player::PLAYER_X);
	b2.make_turn(5, 7, Player::PLAYER_O);
	b2.make_turn(5, 4, Player::PLAYER_X);
	b2.make_turn(6, 7, Player::PLAYER_O);
	DO_CHECK(b2.check_end_game() == GameState::O_WIN);

	b3.make_turn(1, 9, Player::PLAYER_O);
	b3.make_turn(1, 6, Player::PLAYER_X);
	b3.make_turn(2, 9, Player::PLAYER_O);
	b3.make_turn(2, 6, Player::PLAYER_X);
	b3.make_turn(3, 9, Player::PLAYER_O);
	b3.make_turn(3, 6, Player::PLAYER_X);
	b3.make_turn(4, 9, Player::PLAYER_O);
	b3.make_turn(4, 6, Player::PLAYER_X);
	b3.make_turn(5, 9, Player::PLAYER_O);
	DO_CHECK(b3.check_end_game() == GameState::O_WIN);
};

void BoardTest::test_horizontal_win() {
	Board b, b2, b3;
	b.make_turn(5, 5, Player::PLAYER_O);
	b.make_turn(3, 5, Player::PLAYER_X);
	b.make_turn(5, 6, Player::PLAYER_O);
	b.make_turn(3, 6, Player::PLAYER_X);
	b.make_turn(5, 7, Player::PLAYER_O);
	b.make_turn(3, 7, Player::PLAYER_X);
	b.make_turn(5, 8, Player::PLAYER_O);
	b.make_turn(3, 8, Player::PLAYER_X);
	b.make_turn(5, 9, Player::PLAYER_O);
	DO_CHECK(b.check_end_game() == GameState::O_WIN);

	b2.make_turn(8, 0, Player::PLAYER_O);
	b2.make_turn(6, 0, Player::PLAYER_X);
	b2.make_turn(8, 1, Player::PLAYER_O);
	b2.make_turn(6, 1, Player::PLAYER_X);
	b2.make_turn(8, 2, Player::PLAYER_O);
	b2.make_turn(6, 2, Player::PLAYER_X);
	b2.make_turn(8, 3, Player::PLAYER_O);
	b2.make_turn(6, 3, Player::PLAYER_X);
	b2.make_turn(8, 4, Player::PLAYER_O);
	DO_CHECK(b2.check_end_game() == GameState::O_WIN);

	b3.make_turn(6, 3, Player::PLAYER_O);
	b3.make_turn(4, 3, Player::PLAYER_X);
	b3.make_turn(6, 4, Player::PLAYER_O);
	b3.make_turn(4, 4, Player::PLAYER_X);
	b3.make_turn(6, 5, Player::PLAYER_O);
	b3.make_turn(4, 5, Player::PLAYER_X);
	b3.make_turn(6, 6, Player::PLAYER_O);
	b3.make_turn(4, 6, Player::PLAYER_X);
	b3.make_turn(6, 7, Player::PLAYER_O);
	DO_CHECK(b3.check_end_game() == GameState::O_WIN);
};

void BoardTest::test_main_diagonal_win() {
	Board b, b2, b3;
	b.make_turn(0, 0, Player::PLAYER_O);
	b.make_turn(1, 0, Player::PLAYER_X);
	b.make_turn(1, 1, Player::PLAYER_O);
	b.make_turn(2, 1, Player::PLAYER_X);
	b.make_turn(2, 2, Player::PLAYER_O);
	b.make_turn(3, 2, Player::PLAYER_X);
	b.make_turn(3, 3, Player::PLAYER_O);
	b.make_turn(4, 3, Player::PLAYER_X);
	b.make_turn(4, 4, Player::PLAYER_O);

	DO_CHECK(b.check_end_game() == GameState::O_WIN);

	b2.make_turn(5, 3, Player::PLAYER_O);
	b2.make_turn(4, 3, Player::PLAYER_X);
	b2.make_turn(6, 4, Player::PLAYER_O);
	b2.make_turn(5, 4, Player::PLAYER_X);
	b2.make_turn(7, 5, Player::PLAYER_O);
	b2.make_turn(6, 5, Player::PLAYER_X);
	b2.make_turn(8, 6, Player::PLAYER_O);
	b2.make_turn(7, 6, Player::PLAYER_X);
	b2.make_turn(9, 7, Player::PLAYER_O);
	DO_CHECK(b2.check_end_game() == GameState::O_WIN);

	b3.make_turn(1, 4, Player::PLAYER_O);
	b3.make_turn(3, 1, Player::PLAYER_X);
	b3.make_turn(2, 5, Player::PLAYER_O);
	b3.make_turn(4, 2, Player::PLAYER_X);
	b3.make_turn(3, 6, Player::PLAYER_O);
	b3.make_turn(5, 3, Player::PLAYER_X);
	b3.make_turn(4, 7, Player::PLAYER_O);
	b3.make_turn(6, 4, Player::PLAYER_X);
	b3.make_turn(5, 8, Player::PLAYER_O);
	DO_CHECK(b3.check_end_game() == GameState::O_WIN);
};

void BoardTest::test_side_diagonal_win() {
	Board b, b2, b3;
	b.make_turn(5, 1, Player::PLAYER_O);
	b.make_turn(6, 1, Player::PLAYER_X);
	b.make_turn(4, 2, Player::PLAYER_O);
	b.make_turn(5, 2, Player::PLAYER_X);
	b.make_turn(3, 3, Player::PLAYER_O);
	b.make_turn(4, 3, Player::PLAYER_X);
	b.make_turn(2, 4, Player::PLAYER_O);
	b.make_turn(3, 4, Player::PLAYER_X);
	b.make_turn(1, 5, Player::PLAYER_O);
	DO_CHECK(b.check_end_game() == GameState::O_WIN);

	b2.make_turn(9, 0, Player::PLAYER_O);
	b2.make_turn(8, 0, Player::PLAYER_X);
	b2.make_turn(8, 1, Player::PLAYER_O);
	b2.make_turn(7, 1, Player::PLAYER_X);
	b2.make_turn(7, 2, Player::PLAYER_O);
	b2.make_turn(6, 2, Player::PLAYER_X);
	b2.make_turn(6, 3, Player::PLAYER_O);
	b2.make_turn(5, 3, Player::PLAYER_X);
	b2.make_turn(5, 4, Player::PLAYER_O);
	DO_CHECK(b2.check_end_game() == GameState::O_WIN);

	b3.make_turn(8, 4, Player::PLAYER_O);
	b3.make_turn(6, 1, Player::PLAYER_X);
	b3.make_turn(7, 5, Player::PLAYER_O);
	b3.make_turn(5, 2, Player::PLAYER_X);
	b3.make_turn(6, 6, Player::PLAYER_O);
	b3.make_turn(4, 3, Player::PLAYER_X);
	b3.make_turn(5, 7, Player::PLAYER_O);
	b3.make_turn(3, 4, Player::PLAYER_X);
	b3.make_turn(4, 8, Player::PLAYER_O);
	DO_CHECK(b3.check_end_game() == GameState::O_WIN);
};

void BoardTest::test_draw() {
	Board b;
	b.make_turn(0, 0, Player::PLAYER_O);
	b.make_turn(0, 1, Player::PLAYER_X);
	b.make_turn(0, 2, Player::PLAYER_O);
	b.make_turn(0, 3, Player::PLAYER_X);
	b.make_turn(0, 4, Player::PLAYER_O);
	b.make_turn(0, 5, Player::PLAYER_X);
	b.make_turn(0, 6, Player::PLAYER_O);
	b.make_turn(0, 7, Player::PLAYER_X);
	b.make_turn(0, 8, Player::PLAYER_O);
	b.make_turn(0, 9, Player::PLAYER_X);
	b.make_turn(1, 0, Player::PLAYER_O);
	b.make_turn(1, 1, Player::PLAYER_X);
	b.make_turn(1, 2, Player::PLAYER_O);
	b.make_turn(1, 3, Player::PLAYER_X);
	b.make_turn(1, 4, Player::PLAYER_O);
	b.make_turn(1, 5, Player::PLAYER_X);
	b.make_turn(1, 6, Player::PLAYER_O);
	b.make_turn(1, 7, Player::PLAYER_X);
	b.make_turn(1, 8, Player::PLAYER_O);
	b.make_turn(1, 9, Player::PLAYER_X);
	b.make_turn(2, 1, Player::PLAYER_O);
	b.make_turn(2, 0, Player::PLAYER_X);
	b.make_turn(2, 3, Player::PLAYER_O);
	b.make_turn(2, 2, Player::PLAYER_X);
	b.make_turn(2, 5, Player::PLAYER_O);
	b.make_turn(2, 4, Player::PLAYER_X);
	b.make_turn(2, 7, Player::PLAYER_O);
	b.make_turn(2, 6, Player::PLAYER_X);
	b.make_turn(2, 9, Player::PLAYER_O);
	b.make_turn(2, 8, Player::PLAYER_X);
	b.make_turn(3, 1, Player::PLAYER_O);
	b.make_turn(3, 0, Player::PLAYER_X);
	b.make_turn(3, 3, Player::PLAYER_O);
	b.make_turn(3, 2, Player::PLAYER_X);
	b.make_turn(3, 5, Player::PLAYER_O);
	b.make_turn(3, 4, Player::PLAYER_X);
	b.make_turn(3, 7, Player::PLAYER_O);
	b.make_turn(3, 6, Player::PLAYER_X);
	b.make_turn(3, 9, Player::PLAYER_O);
	b.make_turn(3, 8, Player::PLAYER_X);
	b.make_turn(4, 0, Player::PLAYER_O);
	b.make_turn(4, 1, Player::PLAYER_X);
	b.make_turn(4, 2, Player::PLAYER_O);
	b.make_turn(4, 3, Player::PLAYER_X);
	b.make_turn(4, 4, Player::PLAYER_O);
	b.make_turn(4, 5, Player::PLAYER_X);
	b.make_turn(4, 6, Player::PLAYER_O);
	b.make_turn(4, 7, Player::PLAYER_X);
	b.make_turn(4, 8, Player::PLAYER_O);
	b.make_turn(4, 9, Player::PLAYER_X);
	b.make_turn(5, 0, Player::PLAYER_O);
	b.make_turn(5, 1, Player::PLAYER_X);
	b.make_turn(5, 2, Player::PLAYER_O);
	b.make_turn(5, 3, Player::PLAYER_X);
	b.make_turn(5, 4, Player::PLAYER_O);
	b.make_turn(5, 5, Player::PLAYER_X);
	b.make_turn(5, 6, Player::PLAYER_O);
	b.make_turn(5, 7, Player::PLAYER_X);
	b.make_turn(5, 8, Player::PLAYER_O);
	b.make_turn(5, 9, Player::PLAYER_X);
	b.make_turn(6, 1, Player::PLAYER_O);
	b.make_turn(6, 0, Player::PLAYER_X);
	b.make_turn(6, 3, Player::PLAYER_O);
	b.make_turn(6, 2, Player::PLAYER_X);
	b.make_turn(6, 5, Player::PLAYER_O);
	b.make_turn(6, 4, Player::PLAYER_X);
	b.make_turn(6, 7, Player::PLAYER_O);
	b.make_turn(6, 6, Player::PLAYER_X);
	b.make_turn(6, 9, Player::PLAYER_O);
	b.make_turn(6, 8, Player::PLAYER_X);
	b.make_turn(7, 1, Player::PLAYER_O);
	b.make_turn(7, 0, Player::PLAYER_X);
	b.make_turn(7, 3, Player::PLAYER_O);
	b.make_turn(7, 2, Player::PLAYER_X);
	b.make_turn(7, 5, Player::PLAYER_O);
	b.make_turn(7, 4, Player::PLAYER_X);
	b.make_turn(7, 7, Player::PLAYER_O);
	b.make_turn(7, 6, Player::PLAYER_X);
	b.make_turn(7, 9, Player::PLAYER_O);
	b.make_turn(7, 8, Player::PLAYER_X);
	b.make_turn(8, 0, Player::PLAYER_O);
	b.make_turn(8, 1, Player::PLAYER_X);
	b.make_turn(8, 2, Player::PLAYER_O);
	b.make_turn(8, 3, Player::PLAYER_X);
	b.make_turn(8, 4, Player::PLAYER_O);
	b.make_turn(8, 5, Player::PLAYER_X);
	b.make_turn(8, 6, Player::PLAYER_O);
	b.make_turn(8, 7, Player::PLAYER_X);
	b.make_turn(8, 8, Player::PLAYER_O);
	b.make_turn(8, 9, Player::PLAYER_X);
	b.make_turn(9, 0, Player::PLAYER_O);
	b.make_turn(9, 1, Player::PLAYER_X);
	b.make_turn(9, 2, Player::PLAYER_O);
	b.make_turn(9, 3, Player::PLAYER_X);
	b.make_turn(9, 4, Player::PLAYER_O);
	b.make_turn(9, 5, Player::PLAYER_X);
	b.make_turn(9, 6, Player::PLAYER_O);
	b.make_turn(9, 7, Player::PLAYER_X);
	b.make_turn(9, 8, Player::PLAYER_O);
	b.make_turn(9, 9, Player::PLAYER_X);
	DO_CHECK(b.check_end_game() == GameState::DRAW);
};

void BoardTest::test_cur_player(){
	Board b;
	DO_CHECK(b.who_play() == Player::PLAYER_O);
	b.make_turn(9, 0, Player::PLAYER_O);
	DO_CHECK(b.who_play() == Player::PLAYER_X);
	b.make_turn(9, 7, Player::PLAYER_X);
	DO_CHECK(b.who_play() == Player::PLAYER_O);
};

void BoardTest::test_game_state(){
	Board b;
	DO_CHECK(b.check_end_game() == GameState::GAME);
	b.make_turn(9, 0, Player::PLAYER_O);
	DO_CHECK(b.check_end_game() == GameState::GAME);
	b.make_turn(9, 7, Player::PLAYER_X);
	DO_CHECK(b.check_end_game() == GameState::GAME);
};

void BoardTest::runAllTests() {
	test_not_end_game();
	test_O_wins();
	test_X_wins();
	test_bad_turns();
	test_vertical_win();
	test_horizontal_win();
	test_main_diagonal_win();
	test_side_diagonal_win();
	test_draw();
	test_cur_player();
	test_game_state();
};