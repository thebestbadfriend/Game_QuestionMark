#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Game {
public:
	Game();
	~Game();

	void Init(const char* title, int x, int y, int width, int height, bool fullscreen);
	void HandleEvents();
	void UpdateFrame(float deltaTime);
	void RenderFrame();
	//void CleanupFrame(); //maybe?
	void CleanupGame();

	bool IsRunning() { return isRunning; }

private:
	bool isRunning = false;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Texture* playerTexture = nullptr;
	SDL_Rect dstRect;
	float frame = 0;
	int pixelsPerSecond = 3200;
};