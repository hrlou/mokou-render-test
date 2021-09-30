#pragma once 
#include "Texture.hpp"
#include <memory>

class TextureManager {
public:
	static TextureManager* Instance() {
		if (!s_pInstance) {
			s_pInstance = new TextureManager();
			std::cerr << "[TextureManger] Initialised" << std::endl;
		}
		return s_pInstance;
	}
	void load(SDL_Renderer* pRenderer, const std::string t_id, const std::string texture);
	void load(SDL_Renderer* pRenderer, const std::string t_id, const std::string texture, const std::string sheet);
	void draw(SDL_Renderer* pRenderer, const std::string t_id, int x, int y, int w, int h, SDL_RendererFlip = SDL_FLIP_NONE);
	void draw_frame(SDL_Renderer* pRenderer, const std::string t_id, const std::string s_id, int frame, int x, int y, int w, int h, SDL_RendererFlip = SDL_FLIP_NONE);
	void clear(const std::string t_id);
private:
	static TextureManager* s_pInstance;

	std::map<std::string, std::unique_ptr<Texture>> m_TextureMap; 
};