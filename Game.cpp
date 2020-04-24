#include "Game.h"
#include <stdio.h>

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

		SDL_Surface* tmpSurface = IMG_Load("thanos.png");
		if (tmpSurface) {
			playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
			SDL_FreeSurface(tmpSurface);
			if (!playerTexture) {
				initSucceeded = false;
				printf("playerTexture could not initialize! SDL_Error: %s\n", SDL_GetError());
			}
		}
		else {
			initSucceeded = false;
			printf("tmpSurface could not be created! IMG_Error: %s\n", IMG_GetError());
		}
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

void Game::UpdateFrame()
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
}


bool texRendered = false; //test code. Take it out when you're freaking done.
void Game::RenderFrame()
{
	SDL_Rect dstRect;
	dstRect.h = 800;
	dstRect.w = 600;
	SDL_RenderClear(renderer);
	if (SDL_RenderCopy(renderer, playerTexture, NULL, NULL) != 0) {
		printf("Player texture could not render! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		if (!texRendered) {
			printf("Player texture rendered successfully!");
		}
		texRendered = true;//the only other texRendered line. Delte it when you delete the other, obviously
	}
	SDL_RenderPresent(renderer);
}

void Game::CleanupGame()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}
