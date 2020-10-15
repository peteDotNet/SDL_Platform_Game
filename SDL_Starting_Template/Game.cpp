#include "Game.hpp"
#include "TextureManager .hpp"
#include "GameObject.hpp"

GameObject* player;
GameObject* player1;
GameObject* water;
SDL_Renderer* Game::renderer = nullptr;
Map* map;


Game::Game() {

}
Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0;

	if (fullscreen == true)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialised!..." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window Created" << std::endl;
		}

		

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;

	}
	else
	{
		isRunning = false;
	}

	
	player = new GameObject("assets/hero.png", 0, 0);
	player1 = new GameObject("assets/hero2.png", 32, 32);
	water = new GameObject("assets/water.png", 32, 32);
	map = new Map();
}

void Game::handleEvents() 
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	}
}

void Game::update() 
{
	player->Update();
	player1->Update();
	//std::cout << count << std::endl;
}

void Game::render()
{
	SDL_RenderClear(renderer);


	map->DrawMap();
	player->Render();
	player1->Render();

	SDL_RenderPresent(renderer);
}

void Game::clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;


}



