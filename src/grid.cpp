#include "grid.h"
#include<cassert>
// builds a grid with every cell dead.
Grid::Grid(int r,int c,bool w) :
	row_cnt(r),
	col_cnt(c),
	wraparound(w)
{
	assert(r > 0 && c > 0 && "Dimensions must be positive!");
	grid.assign(r, std::vector<Cell>(c, Cell::Dead));
}
// return the number of rows
int Grid::rows() const
{
	return row_cnt;
}
// return the number of columns
int Grid::cols() const
{
	return col_cnt;
}
// check if a given cell is within the bounds of the grid
bool Grid::in_bounds(int r, int c) const
{
	return r >= 0 && r < row_cnt && c >= 0 && c < col_cnt;
}
// get the cell at the position (r,c)
Cell Grid::get(int r, int c) const
{
	assert(in_bounds(r, c) && "cell is out of bounds, double check!");
	return grid[r][c];
}
// se the cell at the position (r,c) to state.
void Grid::set(int r, int c, Cell state)
{
	assert(in_bounds(r, c) && "cell is out of bounds, double check!");
	grid[r][c] = state;
}
// clear the grid.
void Grid::clear()
{
	for (auto &row : grid)
	{
		for (auto &cell : row)
		{
			cell = Cell::Dead;
		}
	}
}
// count how many neighbours are alive.
int Grid::count_live_neighbours(int r, int c) const
{
	int alive = 0;
	int dx[] = {-1,0,1,0,-1,1,1,-1};
	int dy[] = {0,1,0,-1,1,1,-1,-1};
	for (int i = 0; i < 8; i++)
	{
		int x;
		int y;
		if (wraparound)
		{
			x = (r + dx[i] + row_cnt) % row_cnt;
			y = (c + dy[i] + col_cnt) % col_cnt;
		}
		else
		{
			x = r + dx[i] ;
			y = c + dy[i] ;
		}
		if (x == r && y == c) continue;
		if (in_bounds(x,y) && grid[x][y] == Cell::Alive)
		{
			alive++;
		}
	}
	return alive;
}
// count how many cells are alive in the whole grid.
int Grid::count_live_cells() const
{
	int alive = 0;
	for (auto& row : grid)
	{
		for (auto& cell : row)
		{
			if (cell == Cell::Alive)
			{
				alive++;
			}
		}
	}
	return alive;
}
