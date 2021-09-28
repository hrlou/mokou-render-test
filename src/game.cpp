#include "Game.hpp"

Game* Game::s_pInstance = nullptr;

SDL_Texture* Mokou;
SDL_Texture* Background;
auto MokouSheet = SpriteSheet("./assets/mokou_sheet.json");

void Game::init(const char* title, int w, int h) {
	// check 
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cerr << "SDL INITIALISED" << std::endl;
		m_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_ALLOW_HIGHDPI);
		m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		m_running = true;
	}
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);


	// Mokou
	SDL_Surface* tmp = IMG_Load("./assets/mokou_sheet.png");
	SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, 147, 187, 236));
	Mokou = SDL_CreateTextureFromSurface(m_pRenderer, tmp);
	SDL_FreeSurface(tmp);

	tmp = IMG_Load("./assets/backgrounds/hakurei_shrine.png");
	Background = SDL_CreateTextureFromSurface(m_pRenderer, tmp);
	SDL_FreeSurface(tmp);
}

void Game::handle_events(void) {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT :
		m_running = false;
		break;
	default:
		break;
	}
}

void Game::update(void) {
	// std::cout << Cycles++ << std::endl;
}

void Game::render(void) {
	SDL_Rect mokou_src_rect = MokouSheet.get("idle").rect(SDL_GetTicks());
	SDL_Rect mokou_dst_rect = {100, 100, mokou_src_rect.w * 2, mokou_src_rect.w * 2};
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, Background, NULL, NULL);
	SDL_RenderCopyEx(m_pRenderer, Mokou, &mokou_src_rect, &mokou_dst_rect, 0, NULL, SDL_FLIP_NONE);
	// SDL_RenderCopy(m_pRenderer, Mokou, &src_rect, &dst_rect);
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean(void) {
	SDL_DestroyTexture(Mokou);

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}