#include "Texture.hpp"
#include "json.hpp"

#include <iostream>
#include <fstream>
#include <map>

Texture::Texture(const std::string texture, SDL_Renderer* pRenderer) {
	SDL_Surface* pTempSurface = IMG_Load(texture.c_str());
	m_pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
}

Texture::~Texture(void) {
	SDL_DestroyTexture(m_pTexture);
}

TextureSheet::TextureSheet(const std::string texture, const std::string sheet, SDL_Renderer* pRenderer) {
	nlohmann::json json;
	std::ifstream(sheet) >> json;
	for (auto a : json["sprites"]) {
		auto s = Sprite(a["x"], a["y"], a["width"], a["height"], a["frames"], a["border"]);
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

/*SpriteSheet::SpriteSheet(const std::string sheet) {

}

SDL_Rect SpriteSheet::get(const std::string name, int frame) {
	return Map[name].frame(frame);
}

*/