/*
  Author: Adrian Smith
  Course: CS 315
  Assignment: Project 2
*/  

#include "cell.hpp"

using namespace wormGame;

Cell::Cell() {
	x = 0;
	y = 0;
}

Cell::Cell( int xCoord, int yCoord ) {
	x = xCoord;
	y = yCoord;
}

Cell Cell::above() {
	return Cell (x, y + 1);
}

Cell Cell::below() {
	return Cell (x, y - 1);
}

Cell Cell::left() {
	return Cell (x - 1, y);
}

Cell Cell::right() {
	return Cell (x + 1, y);
}
