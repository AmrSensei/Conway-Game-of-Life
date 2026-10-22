#pragma once
#include "grid.h"
namespace Patterns 
{
	bool place_block(Grid& grid, int top_row, int left_col);
	bool place_blinker(Grid& grid, int top_row, int left_col);
	bool place_glider(Grid& grid, int top_row, int left_col);
	bool place_toad(Grid& grid, int top_row, int left_col);
	bool place_beacon(Grid& grid, int top_row, int left_col);
	bool place_lightweight_spaceship(Grid& grid, int top_row, int left_col);
}