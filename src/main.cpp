#include "Game.hpp"

#define FPS 60
#define FRAME_DELAY 1000 / FPS

int main(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cerr << "[SDL] Initialised" << std::endl;
	}
	if (IMG_Init(IMG_INIT_PNG) == 0) {
		std::cerr << "[SDL] Image Initialised" << std::endl;
	}
	Uint32 frame_start;
	int frame_time;
	
	Game::Instance()->init("Touhou Game", 1280, 720, 0);

	while (Game::Instance()->running()) {
		frame_start = SDL_GetTicks();

		Game::Instance()->handle_events();
		Game::Instance()->update();
		Game::Instance()->render();

		frame_time = SDL_GetTicks() - frame_start;
		if (FRAME_DELAY > frame_time) {
			SDL_Delay(FRAME_DELAY - frame_time);
		}
	}
	Game::Instance()->clean();
	return 0;
}