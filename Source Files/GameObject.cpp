#include "..\Header Files\GameObject.h"

GameObject::GameObject(SDL_Renderer* in_renderer, const char* in_filepath)
	:
	renderer(in_renderer),
	location(Vec2(0, 0))
{
	texture = TextureManager::LoadTexture(in_renderer, in_filepath);
	dstRect.x = int(location.x);
	dstRect.y = int(location.y);
	dstRect.w = 800;
	dstRect.h = 600;
}

void GameObject::Update(float deltaTime)
{
	location.x += deltaTime * pixelsPerSecond;
	location.y += deltaTime * pixelsPerSecond;

	dstRect.x = int(location.x);
	dstRect.y = int(location.y);
}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, texture, NULL, &dstRect);
}
