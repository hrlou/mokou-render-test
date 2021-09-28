#pragma once 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <string>
#include <map>

#include "SpriteSheet.hpp"
/*
class TextureManager {
public:
	static TextureManager* Instance() {
		if (!s_pInstance) {
			s_pInstance = new TextureManager();
		}
		return s_pInstance;
	}
	void load(std::string, SDL_Renderer*, const std::string, const std::string);
	void draw (string id, int x, int y, int width, int height,
	           SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_FLIP_NONE); //draw the static image.

	void drawFrame(string id, int x, int y, int width, int height,
	               int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE); //draw image sprite

	void clearFromTextureMap(string id);
private:
	static TextureManager* s_pInstance;
};*/