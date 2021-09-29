#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <map>
#include <string>

class Sprite {
public:	
	Sprite(void) {}
	Sprite(int x, int y, int w, int h, int frames, int border)
		: m_x(x), m_y(y), m_w(w), m_h(h), m_frames(frames), m_border(border) {}
	inline SDL_Rect frame(int frame) {
		SDL_Rect r = {m_x + m_border + (frame * m_w) + (m_border * frame), (m_y + m_border), m_w, m_h};
		return r;
	}
	SDL_Rect operator[](int i) { return frame(i); }
private:
	int m_x, m_y, m_w, m_h, m_frames, m_border;
};

class Texture {
public:
	Texture(void) {}
	~Texture(void);
	Texture(SDL_Renderer* pRenderer, const std::string texture);
	SDL_Texture* texture(void) { return m_pTexture; }
	virtual bool is_sheet(void) { return false; }
protected:
	SDL_Texture* m_pTexture;
};

class TextureSheet : public Texture {
public:
	TextureSheet(void) {}
	TextureSheet(SDL_Renderer* pRenderer, const std::string texture, const std::string sheet);
	Sprite sprite(const std::string id);
	bool is_sheet(void) { return true; }
	Sprite operator[](const std::string id) { return sprite(id); }
private:
	std::map<std::string, Sprite> m_Sprites;
};