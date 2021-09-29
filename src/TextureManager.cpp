#include "TextureManager.hpp"
#include <fstream>

TextureManager* TextureManager::s_pInstance = nullptr;

void TextureManager::load(SDL_Renderer* pRenderer, const std::string texture_id, const std::string texture) {
	m_TextureMap[texture_id] = std::unique_ptr<Texture>(new Texture(pRenderer, texture));
	std::cerr << "[TextureManger] Created texture \"" << texture_id << "\": " << texture << std::endl;
}

void TextureManager::load(SDL_Renderer* pRenderer, const std::string texture_id, const std::string texture, const std::string sheet) {
	m_TextureMap[texture_id] = std::unique_ptr<Texture>(new TextureSheet(pRenderer, texture, sheet));
	std::cerr << "[TextureManger] Created texture \"" << texture_id << "\": " << texture << ", " << sheet << std::endl;
}

void TextureManager::draw(SDL_Renderer* pRenderer, const std::string texture_id, int x, int y, int w, int h, SDL_RendererFlip flip) {
	SDL_Rect src_rect = {0, 0, w, h};
	SDL_Rect dst_rect = {x, y, w, h};
	SDL_RenderCopyEx(pRenderer, m_TextureMap[texture_id]->texture(), &src_rect, &dst_rect, 0, NULL, flip);
}

void TextureManager::draw_frame(SDL_Renderer* pRenderer, const std::string texture_id, const std::string sprite_id, int frame, int x, int y, int w, int h, SDL_RendererFlip flip) {
	if (!m_TextureMap[texture_id]->is_sheet()) {
		return draw(pRenderer, texture_id, x, y, w, h);
	}
	TextureSheet* sheet = dynamic_cast<TextureSheet*>(m_TextureMap[texture_id].get());
	SDL_Rect src_rect = sheet->sprite(sprite_id)[frame];
	SDL_Rect dst_rect = {x, y, w, h};
	SDL_RenderCopyEx(pRenderer, sheet->texture(), &src_rect, &dst_rect, 0, NULL, flip);
}

void TextureManager::clear(const std::string texture_id) {
	std::cout << "[TextureManger] Destroying texture \"" << texture_id << "\"" << std::endl; 
	m_TextureMap.erase(texture_id);
}