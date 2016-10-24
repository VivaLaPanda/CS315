/*
  Author: Adrian Smith
  Course: CS 315
  Assignment: Project 2
*/  

#include "renderEngine.hpp"

using namespace wormGame;


class invalidScreen: public std::exception {
  virtual const char* what() const throw()
  {
	// std::raise(SIGINT);
    return "Attempted to create a screen that failed to meet requirements.";
  }
} invalidScreen;

// Width and height are the width of 
RenderEngine::RenderEngine(unsigned int screenWidth, unsigned int screenHeight) {
	if (screenWidth < 16) {
		throw invalidScreen;
	}
	
	if (screenHeight < 4) {
		throw invalidScreen;
	}
	
	width = screenWidth;
	height = screenHeight;
	
	initscr();	    /* activate curses                                            */
	curs_set(0);   /* prevent the cursor to be displayed                         */
	clear();	    /* clear the screen that curses provides                      */           
	noecho();	    /* prevent the input chars to be echoed to the screen         */      
	cbreak();	    /* change the stty so that characters are delivered to the
					program as they are typed--no need to hit the return key!  */
	
	/* ---------- Horizontal Borders ------------*/
	
	move(0, 0);  // move the curser to the top- and left-most block.
	addstr("  Worm"); // this string is 6 characters long
	
	// Width minus length of score and of Title
	// Title is 6, Score is 10
	for (unsigned int i = 0; i < (width) - 10; i++) {
		move(i + 6, 0);
		addch(' ');
	}
	
	move(0, width - 11);
	addstr("Score:0000"); // This string is 10 chars long
	
	// Printing top border and bottom borders
	for (unsigned int i = 0; i < width + 1; i++) {
		move(1, i);
		addch('*');
		move(height, i);
		addch('*');
	}
	
	/* ---------- Verticle Borders ------------*/
	// Left border
	for (unsigned int i = 0; i < (height - 2); i++) {
		move(i + 2, 0);
		addch('*');
	}
	
	// Right border
	for (unsigned int i = 0; i < (height - 2); i++) {
		move(i + 2, width);
		addch('*');
	}
	
	refreshScreen();
}

Cell RenderEngine::renderPound(Cell poundCell) {
	move(poundCell.y, poundCell.x);
	addch('#');
	
	return poundCell;
}

Cell RenderEngine::renderHead(Cell headCell) {
	move(headCell.y, headCell.x);
	addch('@');
	
	return headCell;
}

Cell RenderEngine::renderBody(Cell bodyCell) {
	move(bodyCell.y, bodyCell.x);
	addch('o');
	
	return bodyCell;
}

Cell RenderEngine::renderMunchie(Cell munchieCell, int munchieValue) {
	move(munchieCell.y, munchieCell.x);
	char val = munchieValue;
	addch(val);
	
	return munchieCell;
}

Cell RenderEngine::removeCell(Cell remCell) {
	move(remCell.y, remCell.x);
	addch(' ');
	
	return remCell;
}

void RenderEngine::renderScore(int score) {
	std::string scoreString = std::to_string(score);
	
	// Player has over 9999 score
	// They basically win
	if (scoreString.length() > 4) {
		move(width - 11, 0);
		addstr(std::string("SuperScore").c_str()); // This string is 10 chars long
	} else {
		// Padding with 0's
		for (unsigned int i = 0; i < 4 - scoreString.length(); i++) {
			scoreString.insert(0, "0");
		}
		scoreString.insert(0, "Score:");
		
		move(width - 11, 0);
		addstr(scoreString.c_str()); // This string is 10 chars long
	}
	
	return;
}

void RenderEngine::refreshScreen() {
	refresh();
	
	return;
}

void RenderEngine::terminate( void )
{
     mvcur( 0, COLS - 1, LINES - 1, 0 );
     clear();
     refresh();
     endwin();
}
