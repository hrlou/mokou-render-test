#include "TextureManager.hpp"
#include <fstream>

TextureManager* TextureManager::s_pInstance = nullptr;

void TextureManager::load(SDL_Renderer* pRenderer, const std::string t_id, const std::string texture) {
	m_TextureMap[t_id] = std::unique_ptr<Texture>(new Texture(pRenderer, texture));
	std::cerr << "[TextureManger] Created texture \"" << t_id << "\": " << texture << std::endl;
}

void TextureManager::load(SDL_Renderer* pRenderer, const std::string t_id, const std::string texture, const std::string sheet) {
	m_TextureMap[t_id] = std::unique_ptr<Texture>(new TextureSheet(pRenderer, texture, sheet));
	std::cerr << "[TextureManger] Created texture \"" << t_id << "\": " << texture << ", " << sheet << std::endl;
}

void TextureManager::draw(SDL_Renderer* pRenderer, const std::string t_id, int x, int y, int w, int h, SDL_RendererFlip flip) {
	if (!m_TextureMap.count(t_id)) {
		std::cerr << "[TextureManger] No such texture \"" << t_id << '"' << std::endl;
		return;
	}
	SDL_Rect src_rect = {0, 0, w, h};
	SDL_Rect dst_rect = {x, y, w, h};
	SDL_RenderCopyEx(pRenderer, m_TextureMap[t_id]->texture(), &src_rect, &dst_rect, 0, NULL, flip);
}

void TextureManager::draw_frame(SDL_Renderer* pRenderer, const std::string t_id, const std::string s_id, int frame, int x, int y, int w, int h, SDL_RendererFlip flip) {
	if (!m_TextureMap.count(t_id)) {
		std::cerr << "[TextureManger] No such texture \"" << t_id << '"' << std::endl;
		return;
	}
	TextureSheet* sheet = dynamic_cast<TextureSheet*>(m_TextureMap[t_id].get());
	if (!sheet) {
		std::cerr << "[TextureManger] \"" << t_id << "\" contains no frames" << std::endl;
		return draw(pRenderer, t_id, x, y, w, h);
	}
	SDL_Rect src_rect = sheet->sprite(s_id)[frame];
	SDL_Rect dst_rect = {x, y, w, h};
	SDL_RenderCopyEx(pRenderer, sheet->texture(), &src_rect, &dst_rect, 0, NULL, flip);
}

void TextureManager::clear(const std::string t_id) {
	std::cout << "[TextureManger] Destroying texture \"" << t_id << "\"" << std::endl; 
	m_TextureMap.erase(t_id);
}