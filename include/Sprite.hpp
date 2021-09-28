#pragma once
#include <SDL2/SDL.h>

class Sprite {
public:	
	Sprite(void) {}
	Sprite(int _x, int _y, int _width, int _height, int _frames, int _border)
		: x(_x), y(_y), width(_width), height(_height), frames(_frames), border(_border) {}
	inline SDL_Rect rect(Uint32 sprite) {
		int frame = (sprite / 100) % frames;
		SDL_Rect r = {x + border + (frame * width) + (border * frame), (y + border), width, height};
		return r;
	}
	int x, y, width, height, frames, border;
};