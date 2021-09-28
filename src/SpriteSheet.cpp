#include "SpriteSheet.hpp"
#include "json.hpp"

#include <iostream>
#include <fstream>
#include <map>

SpriteSheet::SpriteSheet(const std::string sheet) {
	std::ifstream i(sheet);
	nlohmann::json j;
	i >> j;
	// auto s = Sprite(0, 0, 0, 0, 0, 0);
	for (auto a : j["sprites"]) {
		auto s = Sprite(a["x"], a["y"], a["width"], a["height"], a["frames"], a["border"]);
		Map[a["name"]] = s;
	}
}

Sprite SpriteSheet::get(const std::string name) {
	return Map[name];
}