#include "renderer.h"
#include "config.h"
#include "cell.h"
Renderer::Renderer(std::string_view AliveGlyph, std::string_view DeadGlyph) :
	Alive_glyph(AliveGlyph),
	Dead_glyph(DeadGlyph)
{
}
// create the full frame 
std::string Renderer::build_frame(const Grid& grid, int generation_number) const
{
	size_t target_width = 2*grid.cols();
	std::string title_text = "\033[1;33mConway's Game Of Life\033[0m";
	std::string title;
	if (title_text.length() < target_width)
	{
		size_t padding = (target_width - title_text.length()) / 2;
		title.append(padding, ' ');
	}
	title += title_text;
	title.resize(target_width, ' ');

	std::string separator(target_width, '=');
	std::string Output;

	std::string Gen = "Generation : " + std::to_string(generation_number);
	std::string population = "Population : " + std::to_string(grid.count_live_cells());
	Gen.resize(target_width, ' ');
	population.resize(target_width, ' ');

	Output += title + '\n';
	Output += separator + '\n';
	Output += Gen + '\n';
	Output += population + '\n';
	for (int r = 0; r < grid.rows(); r++)
	{
		for (int c = 0; c < grid.cols(); c++)
		{
			if (grid.get(r, c) == Cell::Alive)
			{
				Output += Alive_glyph;
			}
			else
			{
				Output += Dead_glyph;
			}
		}
		Output += '\n';
	}
	return Output;
}
