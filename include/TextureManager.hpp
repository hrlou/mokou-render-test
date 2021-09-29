#pragma once 
#include "Texture.hpp"
#include <memory>

class TextureManager {
public:
	static TextureManager* Instance() {
		if (!s_pInstance) {
			std::cerr << "[TextureManger] Initialised" << std::endl;
			s_pInstance = new TextureManager();
		}
		return s_pInstance;
	}
	void load(const std::string texture_id, const std::string texture, SDL_Renderer* pRenderer);
	void load(const std::string texture_id, const std::string texture, const std::string sheet, SDL_Renderer* pRenderer);
	void draw(const std::string texture_id, int x, int y, int w, int h, SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_FLIP_NONE);
	void draw_frame(const std::string texture_id, const std::string sprite_id, int frame, int x, int y, int w, int h, SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_FLIP_NONE);
	void clear(const std::string texture_id);
private:
	static TextureManager* s_pInstance;

	std::map<std::string, std::unique_ptr<Texture>> m_TextureMap; 
};