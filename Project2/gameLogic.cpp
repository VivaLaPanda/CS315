/*
  Author: Adrian Smith
  Course: CS 315
  Assignment: Project 2
*/  

#include "gameLogic.hpp"

using namespace wormGame;

// Makes the logical representaion of the board. Playwidth and playHeight
// represent the area in which the worm can move, not including boarders.
GameLogic::GameLogic( unsigned int playWidth, unsigned int playHeight) {
	gameState = new ScreenState(playWidth + 2, playHeight + 3);
	gameRender = new RenderEngine(playWidth + 2, playHeight + 3);
	
	gameRender->renderHead(gameState->growSnakeHead(gameState->getRandFree()));
	genMunchie();
	gameRender->refreshScreen();
	
	growCounter = 0;
}

		
bool GameLogic::moveWorm(char direction) {
	Cell newCell;
	if (direction == char('j')) {
		// Left
		newCell = gameState->getHead().left();
	} else if (direction == char('i')) {
		// Up
		newCell = gameState->getHead().above();
	} else if (direction == char('l')) {
		// Right
		newCell = gameState->getHead().right();
	} else if (direction == char('k')) {
		// Down
		newCell = gameState->getHead().below();
	} else {
		// Invalid key
		// Do nothing
		return true;
	}
	
	if (isMunchie(newCell) || growCounter > 0) {
		// If we need to grow
		if (isMunchie(newCell)) {
			eatMunchie();
		}
		
		gameRender->renderBody(gameState->getHead());
		gameRender->renderHead(gameState->growSnakeHead(newCell));
		
		gameRender->refreshScreen();
		growCounter--;
		
		return true;
	} else if (validMove(newCell)) {
		// If we just need to move
		gameRender->removeCell(gameState->getTail());
		gameRender->renderBody(gameState->getHead());
		gameRender->renderHead(gameState->moveSnakeHead(newCell));
		
		gameRender->refreshScreen();
		return true;
	} else {
		gameRender->refreshScreen();
		return false;
	}
}

void GameLogic::endGame() {
	gameRender->terminate();
	delete gameRender;
	delete gameState;
	
	return;
}

Cell GameLogic::genMunchie() {
	// Gen random val from 1 to 8
	munchieValue = (rand() % 9) + 1;
	munchieCell = gameState->getRandFree();
	gameRender->renderMunchie(gameState->setCellUsed(munchieCell), munchieValue);
	
	return munchieCell;
}

Cell GameLogic::eatMunchie() {
	growCounter += munchieValue;
	score += munchieValue;
	gameRender->renderScore(score);
	gameState->setCellUnused(munchieCell);
	
	return genMunchie();
}

bool GameLogic::isMunchie(Cell newHead){
	if (newHead.x == munchieCell.x && newHead.y == munchieCell.y) {
		return true;
	}
	
	return false;
}

bool GameLogic::validMove(Cell newHead){
	if (gameState->isCellUsed(newHead)) {
		return false;
	}
		
	return true;
}
