#pragma once
#include <SDL.h>
#include <SDL_image.h>

class TextureManager {
public:
	static SDL_Texture* LoadTexture(SDL_Renderer* ren, const char* filepath);

private:

};