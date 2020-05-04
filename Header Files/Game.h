#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include "Map.h"

class Game {
public:
	Game();
	~Game();

	//public functions
	void Init(const char* title, int x, int y, int width, int height, bool fullscreen);
	void HandleEvents();
	void UpdateFrame(float deltaTime);
	void RenderFrame();
	//void CleanupFrame(); //maybe?
	void CleanupGame();

	bool IsRunning() { return isRunning; }

	//public variables
	static SDL_Renderer* renderer;

private:
	bool isRunning = false;

	SDL_Window* window = nullptr;
	GameObject player;
	Map map;
};