/*
  Author: Adrian Smith
  Course: CS 315
  Assignment: Project 2
*/  

#include <iostream>
#include <exception>
#include <assert.h>
#include <unistd.h>
#include "cell.hpp"
#include "getChar.hpp"
#include "gameLogic.hpp"
#include "screenState.hpp"

using namespace wormGame;

bool allCellsUnusedTest ( ScreenState testState );
bool cellUseTest ( ScreenState testState );
bool wormMoveTest ( ScreenState testState );
bool logicStartTest ( unsigned int width, unsigned int height );
bool logicMoveTest ( unsigned int width, unsigned int height );
bool logicKillTest ( unsigned int width, unsigned int height );

int main( int argc, char *argv[] ) {
	try {
		ScreenState state1;
		ScreenState state2(0,0);
		ScreenState state3(100, 100);
		
		// Testing to make sure we can set and get cell use
		assert(cellUseTest(state1) == true);
		assert(cellUseTest(state2) == false);
		assert(cellUseTest(state3) == true);
		
		// Making a new set of testcases
		ScreenState state4;
		ScreenState state5(0,0);
		ScreenState state6(100, 100);
		
		// Checking to make sure initialization worked properly
		assert(allCellsUnusedTest(state4) == true);
		assert(allCellsUnusedTest(state5) == true);
		assert(allCellsUnusedTest(state6) == true);
	} catch (const std::exception& e) {
		std::cout << "Failed to construct ScreenState properly" << std::endl;
		throw e;
	}
	
	try  {
		ScreenState state1;
		wormMoveTest(state1);
	} catch (const std::exception& e) {
		std::cout << "Failed to move generate and move worm" << std::endl;
		throw e;
	}
	
	try {
		assert(logicStartTest(25, 25) == true);
	} catch (const std::exception& e) {
		std::cout << "Failed to initialize graphics and logic" << std::endl;
		throw e;
	}
	
	try {
		assert(logicMoveTest(25, 25) == true);
	} catch (const std::exception& e) {
		std::cout << "Failed to move worm" << std::endl;
		throw e;
	}
	
	try {
		assert(logicKillTest(25, 25) == true);
	} catch (const std::exception& e) {
		std::cout << "Failed to kill worm" << std::endl;
		throw e;
	}
	
	
	std::cout << "Test Successful" << std::endl;
	
	return 0;
}

bool cellUseTest ( ScreenState testState ) {
	Cell testCell1(0,0), testCell2(4,4), testCell3(10,10);
	
	try {
		if (testState.isCellUsed(testCell1) && testState.isCellUsed(testCell2) && testState.isCellUsed(testCell3)) {
			return false;
		}
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return false;
	}
	
	try {
		//std::cout << testState.isCellUsed(testCell1) << std::endl;
		testState.setCellUsed(testCell1);
		//std::cout << testState.isCellUsed(testCell1) << std::endl;
		if (!testState.isCellUsed(testCell1)) {
			return false;
		}
	} catch (std::exception& e) {
		std::cout << "Unable to set cell used" << std::endl;
		std::cout << e.what() << std::endl;
	}
	
	return true;
}

bool allCellsUnusedTest( ScreenState testState ) {
	for (unsigned int i = 1; i < testState.getWidth() - 1; i++) {
		for (unsigned int j = 2; j < testState.getHeight() - 1; j++) {
			Cell newCell(i, j);
			
			if (testState.isCellUsed(newCell)) {
				return false;
			}
		}
	}
	
	return true;
}

bool wormMoveTest( ScreenState testState ) {
	// Testing worm;
	Cell testCell(4,4);
	
	try {
		// Generating worm on screen
		testState.growSnakeHead(testCell);
		testState.growSnakeHead(testCell.right());
		testState.growSnakeHead(testCell.right().below());
		
		// Forcing worm to move in a circle more times than will fit in list
		// Primarily tests circular queue.
		for (unsigned int i = 0; i < (testState.getWidth() * testState.getHeight() * 20); i++) {
			testState.moveSnakeHead(testCell.below());
			testState.moveSnakeHead(testCell);
			testState.moveSnakeHead(testCell.right());
			testState.moveSnakeHead(testCell.right().below());
		}
	} catch (std::exception& e) {
		std::cout << "Worm failed to queue properly" << std::endl;
		std::cout << e.what() << std::endl;
		
		return false;
	}
	
	try {
		return testState.isCellUsed(testCell);
	} catch (std::exception& e) {
		std::cout << "Failed to check cell usage" << std::endl;
		std::cout << e.what() << std::endl;
		
		return false;
	}
	
}

bool logicStartTest ( unsigned int width, unsigned int height ) {
	try {
		GameLogic controller(width, height);
		sleep(1);
		controller.endGame();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return false;
	}
	
	return true;
}

bool logicMoveTest ( unsigned int width, unsigned int height ) {
	GameLogic controller(width, height);
	try {
		sleep(1);
		for (int i = 0; i < 2; i++) {
			controller.moveWorm('l');
			controller.moveWorm('l');
			controller.moveWorm('k');
			controller.moveWorm('k');
			controller.moveWorm('j');
			controller.moveWorm('j');
			controller.moveWorm('i');
			controller.moveWorm('i');
		}
		controller.endGame();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		controller.endGame();
		return false;
	}
	
	return true;
}

bool logicKillTest ( unsigned int width, unsigned int height ) {
	GameLogic controller(width, height);
	try {
		sleep(1);
		for (unsigned int i = 0; i < width + 15; i++) {
			if (controller.moveWorm('l') == false) {
				sleep(5);
				controller.endGame();
				return true;
			}
		}
		controller.endGame();
		return false;
	} catch (std::exception& e) {
		std::cout << "Valid move failed" << std::endl;
		std::cout << e.what() << std::endl;
		sleep(5);
		controller.endGame();
		return false;
	}
	
	return false;
}