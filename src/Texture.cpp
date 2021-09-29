#include "Texture.hpp"
#include "json.hpp"

#include <iostream>
#include <fstream>
#include <map>

SpriteSheet::SpriteSheet(const std::string sheet) {
	std::ifstream i(sheet);
	nlohmann::json j;
	i >> j;
	for (auto a : j["sprites"]) {
		auto s = Sprite(a["x"], a["y"], a["width"], a["height"], a["frames"], a["border"]);
		Map[a["name"]] = s;
	}
}

SDL_Rect SpriteSheet::get(const std::string name, int frame) {
	return Map[name].frame(frame);
}