CFLAGS= -ggdb -std=c++11 -Wall
EXECFILES = getChar.o gameLogic.o screenState.o cell.o renderEngine.o

# Builds
all: test.x

# Controllers and Executables
snake.x: main.o $(EXECFILES)
	g++ $(CFLAGS) -o snake.x main.o $(EXECFILES) -lcurses -ltermcap

test.x: test.o $(EXECFILES)
	g++ $(CFLAGS) -o test.x test.o $(EXECFILES) -lcurses -ltermcap
	
main.o: main.cpp *.hpp
	g++ $(CFLAGS) -c -o main.o main.cpp
	
test.o: test.cpp *.hpp
	g++ $(CFLAGS) -c -o test.o test.cpp
	
# Classes
getChar.o: getChar.hpp getChar.cpp
	g++ $(CFLAGS) -c -o getChar.o getChar.cpp

gameLogic.o: gameLogic.hpp gameLogic.cpp screenState.o cell.o renderEngine.o
	g++ $(CFLAGS) -c -o gameLogic.o gameLogic.cpp

screenState.o: screenState.hpp screenState.cpp cell.cpp
	g++ $(CFLAGS) -c -o screenState.o screenState.cpp

renderEngine.o: renderEngine.hpp renderEngine.cpp
	g++ $(CFLAGS) -c -o renderEngine.o renderEngine.cpp

cell.o: cell.hpp cell.cpp
	g++ $(CFLAGS) -c -o cell.o cell.cpp

# At the shell prompt, type: 
# make clean
# to remove the .o, .x and Emacs backup files.

clean:
	rm -f *.o *.x *~