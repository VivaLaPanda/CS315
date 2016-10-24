/*
  Author: Adrian Smith
  Course: CS 315
  Assignment: Project 2
*/  

#ifndef __CELL_HPP_INCLUDED__   
#define __CELL_HPP_INCLUDED__

namespace wormGame
{
	class Cell
	{
		public :
			Cell();
			Cell( int xCoord, int yCoord );
			
			Cell above();
			Cell below();
			Cell left();
			Cell right();
			
			unsigned int x;
			unsigned int y;
	};
}

#endif