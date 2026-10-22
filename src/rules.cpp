#include "rules.h"

// B3/S23
namespace Rules
{
	Cell next_state(Cell cell, int alive_nighbours)
	{
		if (cell == Cell::Alive)
		{
			// Survive with 2 or 3.
			if (alive_nighbours == 2 || alive_nighbours == 3)
			{
				return Cell::Alive;
			}
			else
			{
				return Cell::Dead;
			}
		}
		else
		{
			// Born with 3
			if (alive_nighbours == 3)
			{
				return Cell::Alive;
			}
			else
			{
				return Cell::Dead;
			}
		}
	}
}