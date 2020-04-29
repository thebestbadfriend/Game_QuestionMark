#include <iostream>
#include "..\Header Files\Game.h"
#include "..\Header Files\FrameTimer.h"

Game game;


int main(int argc, char* argv[])
{
	game.Init("My Game?", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900, false);
	FrameTimer ft;

	while (/*game is running*/ true) {
		float deltaTime = ft.Mark();
		game.HandleEvents();
		game.UpdateFrame(deltaTime);
		game.RenderFrame();
		//game.CleanupFrame(); //maybe?
	}
	
	game.CleanupGame();
	//game.Shutdown(); //free up resources used by the game, handle any errors, perform any other necessary cleanup
	//quit the application
	return 0;
}
