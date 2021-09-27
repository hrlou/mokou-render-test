#include "game.hpp"

SDL_Texture* TestTexture;
// std::vector<SDL_Texture*> Textures;

Game::Game(const char* title, int w, int h) {
	Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WindowFlags::SDL_WINDOW_ALLOW_HIGHDPI);
	Renderer = SDL_CreateRenderer(Window, -1, 0);
	Running = true;

	// Test Texture
	SDL_Surface* tmp = IMG_Load("assets/mokou_sheet.png");
	SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, 147, 187, 236));
	TestTexture = SDL_CreateTextureFromSurface(Renderer, tmp);
	// Textures[1] = SDL_CreateTextureFromSurface(Renderer, tmp);
	SDL_FreeSurface(tmp);
}

Game::~Game() {
	SDL_DestroyTexture(TestTexture);

	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
}

void Game::handle_events() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT :
		Running = false;
		break;
	default:
		break;
	}
}

void Game::update() {
	std::cout << Cycles++ << std::endl;
}

void Game::render() {
	// Sprite intro(0, 11, 256, 256, 9, 1);
	Sprite idle(0, 277, 256, 256, 13, 1);
	SDL_Rect src_rect = idle.rect(SDL_GetTicks());
	SDL_Rect dst_rect = {0, 0, 512, 512};
	SDL_RenderClear(Renderer);
	SDL_RenderCopy(Renderer, TestTexture, &src_rect, &dst_rect);
	SDL_RenderPresent(Renderer);
}