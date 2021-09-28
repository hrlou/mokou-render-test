#pragma once

#include <cstdlib>

#include <iostream>
// #include <vector>
// #include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "SpriteManager.hpp"

class Game {
public:
	Game(const char* title, int w, int h);
	~Game();
	// Game Loop Functions
	void handle_events();
	void update();
	void render();
	void clean();

	inline bool running() { return Running; }
private:
 	SDL_Window* Window;
 	SDL_Renderer* Renderer;

 	bool Running;
 	size_t Cycles;
};