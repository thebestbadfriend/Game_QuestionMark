#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Vec2.h"

class GameObject {
public:
	GameObject() = default;
	GameObject(const char* in_filepath);
	//~GameObject();

	void Update(float deltaTime);
	void Render();

private:
	Vec2 location;
	SDL_Texture* texture;
	SDL_Rect dstRect;

	int pixelsPerSecond = 200;
};