#pragma once
#include<SDL.h>
#include <SDL_image.h>
#include <iostream>

class Game {
public:
	Game();
	~Game();

	SDL_Texture* playerTex;
	SDL_Rect srcR, destR;

	void init(const char* title, int xpos, int ypos,int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	int count = 0;
};