/*
  Author: Adrian Smith
  Course: CS 315
  Assignment: Project 2
*/  

#include <iostream>
#include <exception>
#include "cell.hpp"
#include "getChar.hpp"
#include "gameLogic.hpp"
#include "screenState.hpp"

using namespace wormGame;

void gameEndMessage(GameLogic *controller);
void gameLoop(GameLogic *controller);

int main( int argc, char *argv[] ) {
	// Check the number of parameters
    if (argc < 2) {
		// Make a default game
        GameLogic *controller();
		gameLoop(controller);
    } else  if (argc == 3) {
		unsigned int width = atoi(argv[1]); 
		unsigned int height = atoi(argv[2]); 
		// Make a game with argv[1] width and argv[2] height
		GameLogic * controller = new GameLogic(width, height);
		gameLoop(controller);
	} else {
		// Invalid params
        std::cerr << "Usage: " << argv[0] << " WIDTH" << " HEIGHT" << std::endl;
		
		return 1;
	}
	
	return 0;
}

void gameEndMessage(GameLogic *controller) {
	std::cout << "You have died" << std::endl;
	std::cout << "Your score was: " << controller->getScore() << std::endl;
	
	return;
}

void gameLoop(GameLogic *controller) {
	try {
		while (controller->moveWorm(get_char()) != false) {}
		
		controller->endGame();
	} catch (std::exception& e) {
		controller->endGame();
		std::cerr << "Game terminated unexpectedly" << std::endl;
		std::cerr << e.what() << std::endl;
	}
}