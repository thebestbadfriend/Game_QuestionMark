#pragma once
#include "Game.h"

class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* filepath);
	static void Draw(SDL_Texture* texture, const SDL_Rect* srcRect, const SDL_Rect* dstRect);
private:

};