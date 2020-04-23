#include <iostream>
#include "Game.h"

Game game;

int main(int argc, char* argv[])
{
	game.Init("My Game?", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, true);

	while (/*game is running*/ true) {
		game.HandleEvents();
		game.UpdateFrame();
		game.RenderFrame();
		//game.CleanupFrame(); //maybe?
	}

	game.CleanupGame();
	//game.Shutdown(); //free up resources used by the game, handle any errors, perform any other necessary cleanup
	//quit the application
	return 0;
}
