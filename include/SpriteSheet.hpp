#pragma once
#include "Sprite.hpp"
#include <map>
#include <string>

class SpriteSheet {
public:
	SpriteSheet(const std::string sheet);
	Sprite get(const std::string name);
private:
	std::map<std::string, Sprite> Map;
};