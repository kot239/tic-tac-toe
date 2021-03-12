#include "Test.h"
#include "BoardTest.h"

int main() {
	BoardTest bt;
	bt.runAllTests();
	Test::showFinalResult();
	return Test::code_return();
}