#include "TextureManager.hpp"
#include <fstream>

TextureManager* TextureManager::s_pInstance = nullptr;

void TextureManager::load(const std::string texture_id, const std::string texture, SDL_Renderer* pRenderer) {
	m_TextureMap[texture_id] = std::unique_ptr<Texture>(new Texture(texture, pRenderer));
	std::cerr << "[TextureManger] Created texture \"" << texture_id << "\": " << texture << std::endl;
}

void TextureManager::load(const std::string texture_id, const std::string texture, const std::string sheet, SDL_Renderer* pRenderer) {
	m_TextureMap[texture_id] = std::unique_ptr<Texture>(new TextureSheet(texture, sheet, pRenderer));
	std::cerr << "[TextureManger] Created texture \"" << texture_id << "\": " << texture << ", " << sheet << std::endl;
}

void TextureManager::draw(const std::string texture_id, int x, int y, int w, int h, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
	SDL_Rect src_rect = {0, 0, w, h};
	SDL_Rect dst_rect = {x, y, w, h};
	SDL_RenderCopyEx(pRenderer, m_TextureMap[texture_id]->texture(), &src_rect, &dst_rect, 0, NULL, flip);
}

void TextureManager::draw_frame(const std::string texture_id, const std::string sprite_id, int frame, int x, int y, int w, int h, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
	if (!m_TextureMap[texture_id]->is_sheet()) {
		return draw(texture_id, x, y, w, h, pRenderer);
	}
	TextureSheet* sheet = dynamic_cast<TextureSheet*>(m_TextureMap[texture_id].get());
	SDL_Rect src_rect = sheet->sprite(sprite_id)[frame];
	SDL_Rect dst_rect = {x, y, w, h};
	SDL_RenderCopyEx(pRenderer, sheet->texture(), &src_rect, &dst_rect, 0, NULL, flip);
}

void TextureManager::clear(const std::string texture_id) {
	m_TextureMap.erase(texture_id);
}