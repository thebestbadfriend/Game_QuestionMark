#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Map {
public:
	Map();

	void LoadMap(int level[25][30]);
	void DrawMap();

private:
	int tileSet[25][30];

	SDL_Texture* water;
	SDL_Texture* dirt;
	SDL_Texture* grass;
};