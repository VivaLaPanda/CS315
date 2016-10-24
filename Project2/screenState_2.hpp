#include <exception>
#include <stdlib.h>
#include <time.h>
#include "cell.hpp"

class ScreenState
{
    public :
        ScreenState() : ScreenState(16, 16) {}
        ScreenState( unsigned int screenWidth, unsigned int screenHeight );
		unsigned int getWidth() {  return width; }
		unsigned int getHeight() { return height; }
		
		Cell getRandFree();
		Cell setCellUsed( Cell unusedCell );
		Cell setCellUnused( Cell usedCell );
		bool isCellUsed( Cell usedCell );
		Cell moveSnakeHead( Cell newCell );
		Cell growSnakeHead( Cell newCell );
	
	private : 
		int ** screen;
		Cell * freePool;
		Cell * wormCells;
		unsigned int width;
		unsigned int height;
		
		unsigned int freePoolSize;
		unsigned int wormHead;
		unsigned int wormTail;
		unsigned int wormCellsSize;
};