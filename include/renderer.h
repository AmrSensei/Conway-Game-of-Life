#pragma once
#include<string>
#include <string_view>
#include "grid.h"
class Renderer
{
private:
	std::string Alive_glyph;
	std::string Dead_glyph;
public:
	Renderer(std::string_view AliveGlyph, std::string_view DeadGlyph);
	std::string build_frame(const Grid& grid, int generation_number) const;
};