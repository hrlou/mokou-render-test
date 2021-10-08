#include "Texture.hpp"
#include "json.hpp"

#include <iostream>
#include <fstream>
#include <map>

// inline SDL_Surface*

Texture::Texture(SDL_Renderer* pRenderer, const std::string texture) {
	SDL_Surface* pTempSurface = IMG_Load(texture.c_str());
	if (pTempSurface == nullptr) {
		std::cerr << "[Texture] Failed to create surface \"" << texture << "\": " << IMG_GetError() << std::endl; 
	}
	m_pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	if (m_pTexture == nullptr) {
		std::cerr << "[Texture] Failed to create texture \"" << texture << "\": " << IMG_GetError() << std::endl; 
	}
	SDL_FreeSurface(pTempSurface);
}

Texture::~Texture(void) {
	SDL_DestroyTexture(m_pTexture);
}

TextureSheet::TextureSheet(SDL_Renderer* pRenderer, const std::string texture, const std::string sheet) {
	nlohmann::json json;
	std::ifstream(sheet) >> json;
	int border = 0;
	if (json.contains("border")) {
		border = json["border"];
	}
	for (auto a : json["sprites"]) {
		auto s = Sprite(a["x"], a["y"], a["width"], a["height"], a["frames"], border);
		m_Sprites[a["name"]] = s;
	}
	SDL_Surface* pTempSurface = IMG_Load(texture.c_str());
	if (json.contains("color_key")) {
		SDL_SetColorKey(pTempSurface, SDL_TRUE, SDL_MapRGB(pTempSurface->format, json["color_key"]["r"], json["color_key"]["g"], json["color_key"]["b"]));
	}
	m_pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
}

Sprite TextureSheet::sprite(const std::string id) {
	return m_Sprites[id];
}