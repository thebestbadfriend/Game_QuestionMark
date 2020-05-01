#pragma once
#include "Vec2.h"
#include "TextureManager.h"

class GameObject {
public:
	GameObject() = default;
	GameObject(SDL_Renderer* in_renderer, const char* in_filepath);
	//~GameObject();

	void Update(float deltaTime);
	void Render();

private:
	Vec2 location;
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	SDL_Rect dstRect;

	int pixelsPerSecond = 200;
};