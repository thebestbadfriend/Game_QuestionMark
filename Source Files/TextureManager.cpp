#include <iostream>
#include "..\Header Files\TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filepath)
{
	SDL_Surface* tmpSurface = IMG_Load(filepath);

	if (!tmpSurface) {
		printf("TextureManager::LoadTexture tmpSurface was not created successfully! IMG_Error: %s\n", IMG_GetError());
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);

	if (!tex) {
		printf("TextureMangager::LoadTexture tex was not created successfully! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		printf("TextureManager::LoadTexture created texture %s successfully\n", filepath);
	}
	SDL_FreeSurface(tmpSurface);

	return tex;
}

void TextureManager::Draw(SDL_Texture* texture, const SDL_Rect* srcRect, const SDL_Rect* dstRect)
{
	SDL_RenderCopy(Game::renderer, texture, srcRect, dstRect);
}
