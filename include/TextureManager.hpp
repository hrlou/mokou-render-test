#pragma once 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <string>
#include <map>

#include "Texture.hpp"

class TextureManager {
public:
	static TextureManager* Instance() {
		if (!s_pInstance) {
			s_pInstance = new TextureManager();
		}
		return s_pInstance;
	}
	void load(const std::string id, const std::string texture, SDL_Renderer* pRenderer);
	void draw(const std::string id, int x, int y, int w, int h, SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_FLIP_NONE);
	void draw_frame(const std::string id, const std::string sprite, int frame, int x, int y, int w, int h, SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_FLIP_NONE);
	// void clearFromTextureMap(string id);
private:
	static TextureManager* s_pInstance;

	std::map<std::string, Texture> m_TextureMap; 
};