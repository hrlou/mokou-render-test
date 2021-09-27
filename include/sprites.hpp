#pragma once
#include <SDL2/SDL.h>

class Sprite {
public:
	Sprite(int _X, int _Y, int _Width, int _Height, int _Frames, int _BorderSize)
		: X(_X), Y(_Y), Width(_Width), Height(_Height), Frames(_Frames), BorderSize(_BorderSize) {}
	inline SDL_Rect rect(Uint32 sprite) {
		int frame = (sprite / 100) % Frames;
		SDL_Rect r = {X + BorderSize + (frame * Width) + (BorderSize * frame), (Y + BorderSize), Width, Height};
		return r;
	}
private:
	int X, Y, Width, Height, Frames, BorderSize;
};