/*
  Author: Adrian Smith
  Course: CS 315
  Assignment: Project 2
*/  

#ifndef __RENDER_HPP_INCLUDED__   
#define __RENDER_HPP_INCLUDED__ 

#include <curses.h>
#include <exception>
#include <string>
#include "cell.hpp"

namespace wormGame
{
	class RenderEngine
	{
		public :
			RenderEngine(unsigned int width, unsigned int height);
			Cell renderPound(Cell poundCell);
			Cell renderHead(Cell headCell);
			Cell renderBody(Cell bodyCell);
			Cell renderMunchie(Cell munchieCell, int munchieValue);
			Cell removeCell(Cell remCell);
			void renderScore(int score);
			void refreshScreen();
			
			void terminate( void );
		
		private : 
			unsigned int width;
			unsigned int height;
	};
}

#endif