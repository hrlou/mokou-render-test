#include <SDL2/SDL.h>
#include <cstdlib>

int main(int argc, char* argv[]) {
	SDL_Window* window = SDL_CreateWindow("MY WINDOW", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 400, SDL_WindowFlags::SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Delay(1000);
	SDL_DestroyWindow(window);
	return EXIT_SUCCESS;
}