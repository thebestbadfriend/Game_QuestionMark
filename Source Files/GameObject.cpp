#include "..\Header Files\GameObject.h"
#include "..\Header Files\TextureManager.h"

GameObject::GameObject(const char* in_filepath)
	:
	location(Vec2(0, 0))
{
	texture = TextureManager::LoadTexture(in_filepath);
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
	//SDL_RenderCopy(Game::renderer, texture, NULL, &dstRect);
	TextureManager::Draw(texture, NULL, &dstRect);
}
