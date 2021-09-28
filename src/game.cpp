#include "Game.hpp"

SDL_Texture* TestTexture;
auto MokouSprite = SpriteManager("./assets/mokou_sheet.json");
// std::vector<SDL_Texture*> Textures;

Game::Game(const char* title, int w, int h) {
	Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WindowFlags::SDL_WINDOW_ALLOW_HIGHDPI);
	Renderer = SDL_CreateRenderer(Window, -1, 0);
	Running = true;

	// Test Texture
	SDL_Surface* tmp = IMG_Load("assets/kokoro_sheet.png");
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
	// SDL_Rect src_rect = MokouSprite.get("idle").rect(SDL_GetTicks());
	SDL_Rect src_rect = Sprite(0, 11, 256, 256, 19, 1).rect(SDL_GetTicks());
	SDL_Rect dst_rect = {100, 100, src_rect.w * 2, src_rect.h * 2};
	SDL_RenderClear(Renderer);
	SDL_RenderCopy(Renderer, TestTexture, &src_rect, &dst_rect);
	SDL_RenderPresent(Renderer);
}