/*
  Author: Adrian Smith
  Course: CS 315
  Assignment: Project 2
*/  

#include "cell.hpp"
#include "screenState.hpp"
#include "renderEngine.hpp"
#include <exception>
#include <stdlib.h>
#include <time.h>

#include <iostream>

namespace wormGame
{
	class GameLogic
	{
		public :
			GameLogic() : GameLogic(14, 13) {}
			GameLogic( unsigned int playWidth, unsigned int playHeight );
			
			bool moveWorm(char direction);
			unsigned int getScore() { return score; }
			void endGame();
		private :
			ScreenState *gameState;
			RenderEngine *gameRender;
			Cell genMunchie();
			Cell eatMunchie();
			bool isMunchie(Cell newHead);
			bool validMove(Cell newHead);
			int growCounter;
			
			Cell munchieCell;
			int munchieValue;
			
			unsigned int score;
	};
}