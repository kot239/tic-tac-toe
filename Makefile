all: tic-tac-toe test

tic-tac-toe: obj/Board.o obj/StdioBoardView.o obj/NcursesBoardView.o obj/Controller.o obj/main.o
	g++ -o tic-tac-toe obj/Board.o obj/StdioBoardView.o obj/NcursesBoardView.o obj/Controller.o obj/main.o -lncurses

obj:
	mkdir obj

obj/StdioBoardView.o: src/StdioBoardView.cpp | obj
	g++ -O2 -Wall -Wextra -Werror -std=c++11 src/StdioBoardView.cpp -c -Iinclude -o obj/StdioBoardView.o

obj/NcursesBoardView.o: src/NcursesBoardView.cpp | obj
	g++ -O2 -Wall -Wextra -Werror -std=c++11 src/NcursesBoardView.cpp -c -Iinclude -o obj/NcursesBoardView.o

obj/Board.o: src/Board.cpp | obj
	g++ -O2 -Wall -Wextra -Werror -std=c++11 src/Board.cpp -c -Iinclude -o obj/Board.o

obj/Controller.o: src/Controller.cpp | obj
	g++ -O2 -Wall -Wextra -Werror -std=c++11 src/Controller.cpp -c -Iinclude -o obj/Controller.o

obj/main.o: src/main.cpp | obj
	g++ -O2 -Wall -Wextra -Werror -std=c++11 src/main.cpp -c -Iinclude -o obj/main.o

test: obj/Test.o obj/BoardTest.o obj/mainTest.o obj/Board.o
	g++ -o test obj/Test.o obj/BoardTest.o obj/mainTest.o obj/Board.o

obj/Test.o: testing/Test.cpp | obj
	g++ -O2 -Wall -Wextra -Werror -std=c++11 testing/Test.cpp -c -Iinclude -o obj/Test.o

obj/BoardTest.o: testing/BoardTest.cpp | obj
	g++ -O2 -Wall -Wextra -Werror -std=c++11 testing/BoardTest.cpp -c -Iinclude -o obj/BoardTest.o

obj/mainTest.o: testing/mainTest.cpp | obj
	g++ -O2 -Wall -Wextra -Werror -std=c++11 testing/mainTest.cpp -c -Iinclude -o obj/mainTest.o

clean:
	rm -rf obj tic-tac-toe test