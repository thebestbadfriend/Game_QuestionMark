#include <iostream>
#include "..\Header Files\TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filepath)
{
	SDL_Surface* tmpSurface = IMG_Load(filepath);

	if (!tmpSurface) {
		printf("TextureManager::LoadTexture tmpSurface was not created successfully! IMG_Error: %s\n", IMG_GetError());
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return tex;
}
