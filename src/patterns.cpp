#include "patterns.h"

namespace Patterns
{
	// check if the starting point and the end are withing bounds
	bool fits(const Grid& grid,int top_row,int left_col,int h,int w)
	{
		return grid.in_bounds(top_row, left_col) && grid.in_bounds(top_row + h - 1, left_col + w - 1);
	}
	/*
	*	a block looks like 
	*     OO
	*     OO
	*/
	bool place_block(Grid& grid, int top_row, int left_col)
	{
		if (!fits(grid,top_row,left_col,2,2))
		{
			return false;
		}
		grid.set(top_row,left_col,Cell::Alive);
		grid.set(top_row + 1, left_col, Cell::Alive);
		grid.set(top_row, left_col + 1, Cell::Alive);
		grid.set(top_row + 1, left_col + 1, Cell::Alive);
		return true;
	}
	/*
	*	a blinker looks like
	*     OOO
	*/
	bool place_blinker(Grid& grid, int top_row, int left_col)
	{
		if (!fits(grid, top_row, left_col, 1, 3))
		{
			return false;
		}
		grid.set(top_row, left_col, Cell::Alive);
		grid.set(top_row, left_col + 1, Cell::Alive);
		grid.set(top_row, left_col + 2, Cell::Alive);
		return true;
	}
	/*
	* 	* a glider looks like
	*      .O.
	*      ..O
	*      OOO
	*/
	bool place_glider(Grid& grid, int top_row, int left_col)
	{
		if (!fits(grid, top_row, left_col, 3, 3))
		{
			return false;
		}
		grid.set(top_row, left_col + 1, Cell::Alive);
		grid.set(top_row + 1, left_col + 2, Cell::Alive);
		grid.set(top_row + 2, left_col, Cell::Alive);
		grid.set(top_row + 2, left_col + 1, Cell::Alive);
		grid.set(top_row + 2, left_col + 2, Cell::Alive);
		return true;
	}
	/*
	* 	* a toad looks like
	*      .OO.
	*      O...
	*      ...O
	*	   .OO.
	*/
	bool place_toad(Grid& grid, int top_row, int left_col)
	{
		if (!fits(grid, top_row, left_col, 4, 4))
		{
			return false;
		}
		grid.set(top_row, left_col + 1, Cell::Alive);
		grid.set(top_row, left_col + 2, Cell::Alive);
		grid.set(top_row + 1, left_col, Cell::Alive);
		grid.set(top_row + 2, left_col + 3, Cell::Alive);
		grid.set(top_row + 3, left_col + 1, Cell::Alive);
		grid.set(top_row + 3, left_col + 2, Cell::Alive);
		return true;
	}
	/*
	* 	* a beacon looks like
	*      OO..
	*	   OO..
	*      ..OO
	*      ..OO
	*/
	bool place_beacon(Grid& grid, int top_row, int left_col)
	{
		if (!fits(grid, top_row, left_col, 4, 4))
		{
			return false;
		}
		place_block(grid, top_row, left_col);
		place_block(grid, top_row + 2, left_col + 2);
		return true;
	}
	bool place_lightweight_spaceship(Grid& grid, int top_row, int left_col)
	{
		if (!fits(grid, top_row, left_col, 4, 5))
		{
			return false;
		}
		grid.set(top_row, left_col + 1, Cell::Alive);
		grid.set(top_row + 1, left_col, Cell::Alive);
		grid.set(top_row + 2, left_col, Cell::Alive);
		grid.set(top_row + 3, left_col , Cell::Alive);
		grid.set(top_row, left_col + 4, Cell::Alive);
		grid.set(top_row + 2, left_col + 4, Cell::Alive);
		grid.set(top_row + 3, left_col + 1, Cell::Alive);
		grid.set(top_row + 3, left_col + 2, Cell::Alive);
		grid.set(top_row + 3, left_col + 3, Cell::Alive);
		return true;
	}
}