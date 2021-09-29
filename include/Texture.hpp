#pragma once
#include <SDL2/SDL.h>

#include <map>
#include <string>

class Sprite {
public:	
	Sprite(void) {}
	Sprite(int _x, int _y, int _width, int _height, int _frames, int _border)
		: x(_x), y(_y), width(_width), height(_height), frames(_frames), border(_border) {}
	inline SDL_Rect frame(int frame) {
		SDL_Rect r = {x + border + (frame * width) + (border * frame), (y + border), width, height};
		return r;
	}
	int x, y, width, height, frames, border;
};

class SpriteSheet {
public:
	SpriteSheet(void) {}
	SpriteSheet(const std::string sheet);
	SDL_Rect get(const std::string name, int frame = 0);
private:
	std::map<std::string, Sprite> Map;
};

class Texture {
public:
	Texture(void) {}
	Texture(const std::string texture, SDL_Renderer* pRenderer);
	SDL_Texture* texture(void) { return m_pTexture; }
	SpriteSheet sheet(void) { return m_SpriteSheet; }
private:
	SDL_Texture* m_pTexture;
	SpriteSheet m_SpriteSheet;
	bool m_HasSheet;
};