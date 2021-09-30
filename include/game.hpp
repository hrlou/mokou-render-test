#pragma once

#include <cstdlib>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "TextureManager.hpp"

class Game {
public:
	static Game* Instance() {
		if (!s_pInstance) {
			s_pInstance = new Game();
			std::cerr << "[Game] Initialised" << std::endl;
		}
		return s_pInstance;
	}
	// Game Loop Functions
	void init(const char* title, int w, int h, Uint32 flags);
	void handle_events(void);
	void update(void);
	void render(void);
	void clean(void);

	inline bool running() { return m_running; }
private:
	static Game* s_pInstance;

 	SDL_Window* m_pWindow = nullptr;
 	SDL_Renderer* m_pRenderer = nullptr;

 	bool m_running = false;
};