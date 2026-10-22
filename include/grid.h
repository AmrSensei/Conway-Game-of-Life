#pragma once
#include <vector>
#include "cell.h"

class Grid
{
private:
	int row_cnt;
	int col_cnt;
	std::vector<std::vector<Cell>>grid;
	bool wraparound;

public:
	Grid(int r,int c, bool w);
	int rows() const;
	int cols() const;
	bool in_bounds(int r, int c) const;
	Cell get(int r, int c) const;
	void set(int r, int c, Cell state);
	void clear();
	int count_live_neighbours(int r, int c) const;
	int count_live_cells() const;
};