#include <stdio.h>
#include "..\Header Files\Game.h"

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init(const char* title, int x, int y, int width, int height, bool fullscreen)
{
	bool initSucceeded = true;
	int flags = 0;

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		printf("SDL initialized successfully!\n");

		window = SDL_CreateWindow(title, x, y, width, height, flags);
		if (window) {
			printf("Window created successfully!\n");
		}
		else {
			initSucceeded = false;
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			printf("Renderer created successfully!\n");
		}
		else {
			initSucceeded = false;
			printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		}

		player = GameObject("Images\\thanos.png");
		map = Map();
	}
	else {
		initSucceeded = false;
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}

	if (initSucceeded) {
		isRunning = true;
	}
}

void Game::HandleEvents()
{
	SDL_Event sdl_event;
	SDL_PollEvent(&sdl_event);

	switch (sdl_event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::UpdateFrame(float deltaTime)
{
	player.Update(deltaTime);
	//SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
}

void Game::RenderFrame()
{
	SDL_RenderClear(renderer);

	map.DrawMap();
	player.Render();

	SDL_RenderPresent(renderer);
}

void Game::CleanupGame()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}
