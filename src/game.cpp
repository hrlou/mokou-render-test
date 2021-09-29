#include "Game.hpp"
#include "TextureManager.hpp"

Game* Game::s_pInstance = nullptr;

void Game::init(const char* title, int w, int h) {
	// check 
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		m_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_ALLOW_HIGHDPI);
		m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		m_running = true;
	}
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
	TextureManager::Instance()->load("hakurei_shrine", "./assets/backgrounds/hakurei_shrine.png", m_pRenderer);
	TextureManager::Instance()->load("mokou", "./assets/mokou_sheet.png", "./assets/mokou_sheet.json", m_pRenderer);
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
	SDL_RenderClear(m_pRenderer);
	TextureManager::Instance()->draw("hakurei_shrine", 0, 0, 1280, 720, m_pRenderer);
	TextureManager::Instance()->draw_frame("mokou", "idle", (SDL_GetTicks() / 100) % 13, 0, 0, 512, 512, m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean(void) {
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}