#include "screenState.hpp"

class cellOutOfBoundsException: public std::exception {
  virtual const char* what() const throw()
  {
	// std::raise(SIGINT);
    return "Attempted to access out of bounds cell";
  }
} cellOutOfBoundsException;

ScreenState::ScreenState( unsigned int screenWidth, unsigned int screenHeight ) {
	width = screenWidth;
	height = screenHeight;
	
	screen = new int * [width];
	
	for (unsigned int i = 0; i < width; i++) {
		screen[i] = new int[height];
	}
	
	freePool = new Cell [width * height];
	freePoolSize = width * height;
	
	wormCells = new Cell [width * height];
	wormCellsSize = width * height;
	wormHead = 0;
	wormTail = 0;
	
	// Filling data structures with starting values
	unsigned int cellCount = 0;
	for (unsigned int i; i < width; i++) {
		for (unsigned int j; j < height; j++) {
			screen[i][j] = cellCount;
			Cell newCell(i, j);
			freePool[cellCount] = newCell;
			
			cellCount++;
		}
	}
	
	return;
}

Cell ScreenState::getRandFree() {
	srand (time(NULL));
	int randIndex = rand() % freePoolSize + 1;
	
	Cell newCell = freePool[randIndex];
	
	return newCell;
}

Cell ScreenState::setCellUsed( Cell unusedCell ) {
	if (isCellUsed(unusedCell)) {
		return;
	}
	
	unsigned int savedFreePoolSize = freePoolSize;
	int usedIndex = screen[unusedCell.x][unusedCell.y];
	Cell elementToSwap = freePool[usedIndex];
	Cell elementToRemove = freePool[freePoolSize - 1];
	
	try {
		screen[unusedCell.x][unusedCell.y] = -1;
		Cell tempCell;
		tempCell = freePool[usedIndex];
		freePool[usedIndex] = freePool[freePoolSize - 1];;
		freePool[freePoolSize - 1] = tempCell;
		freePoolSize--;
	} catch (std::exception& e) {
		screen[unusedCell.x][unusedCell.y] = usedIndex;
		freePoolSize = savedFreePoolSize;
		freePool[usedIndex] = elementToSwap;
		freePool[freePoolSize - 1] = elementToRemove;
	}
	
	return unusedCell;
}

Cell ScreenState::setCellUnused( Cell usedCell ) {
	if (!isCellUsed(usedCell)) {
		return;
	}
	
	freePool[freePoolSize] = usedCell;
	screen[usedCell.x][usedCell.y] = freePoolSize;
	freePoolSize++;
	
	return usedCell;
}

bool ScreenState::isCellUsed( Cell usedCell ) {
	if (usedCell.x + 1 > width || usedCell.y + 1 > height) {
		throw cellOutOfBoundsException;
	}
	
	if (screen[usedCell.x][usedCell.y] == -1) {
		return true;
	}
	
	return false;
}

Cell ScreenState::moveSnakeHead( Cell newCell ) {
	// Storing the new head and marking it as used
	wormCells[wormHead] = newCell;
	
	// Circular Queue : If we go off one end of the array we wrap around to the beginning
	setCellUsed(newCell);
	if (wormHead == wormCellsSize - 1) {
		wormHead = 0;
	} else {
		wormHead++;
	}
	
	setCellUnused(wormCells[wormTail]);
	if (wormTail == wormCellsSize - 1) {
		wormTail = 0;
	} else {
		wormTail++;
	}
	
	
	return wormCells[wormHead];
}

Cell ScreenState::growSnakeHead( Cell newCell ) {
	wormCells[wormHead] = newCell;
	
	// Circular Queue : If we go off one end of the array we wrap around to the beginning
	setCellUsed(newCell);
	if (wormHead == wormCellsSize - 1) {
		wormHead = 0;
	} else {
		wormHead++;
	}
	
	return wormCells[wormHead];
}
