#pragma once
#include "grid.h"

class Simulation
{
private:
	Grid current;
	Grid next;
	int generation_cnt;

public:
	Simulation(Grid &initial);
	void step();
	const Grid& grid() const;
	int generation() const;
};