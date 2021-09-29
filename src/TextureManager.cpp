#include <fstream>

#include "TextureManager.hpp"

TextureManager* TextureManager::s_pInstance = nullptr;

Texture::Texture(const std::string texture, SDL_Renderer* pRenderer) {
	// check if sheet json exists
	std::string sheet = (texture.substr(0, texture.find_last_of("."))) + ".json";
	m_HasSheet = std::ifstream(sheet).good();
	if (m_HasSheet) {
		m_SpriteSheet = SpriteSheet(sheet);
	}
	SDL_Surface* tmp = IMG_Load(texture.c_str());
	// SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, 147, 187, 236));
	m_pTexture = SDL_CreateTextureFromSurface(pRenderer, tmp);
	SDL_FreeSurface(tmp);
}

void TextureManager::load(const std::string id, const std::string texture, SDL_Renderer* pRenderer) {
	m_TextureMap[id] = Texture(texture, pRenderer);
}

void TextureManager::draw(const std::string id, int x, int y, int w, int h, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
	SDL_Rect src_rect = {0, 0, w, h};
 	SDL_Rect dst_rect = {x, y, w, h};
	SDL_RenderCopyEx(pRenderer, m_TextureMap[id].texture(), &src_rect, &dst_rect, 0, NULL, flip);
}

void TextureManager::draw_frame(const std::string id, const std::string sprite, int frame, int x, int y, int w, int h, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
	SDL_Rect src_rect = m_TextureMap[id].sheet().get(sprite, frame);
	SDL_Rect dst_rect = {x, y, w, h};
	SDL_RenderCopyEx(pRenderer, m_TextureMap[id].texture(), &src_rect, &dst_rect, 0, NULL, flip);
}