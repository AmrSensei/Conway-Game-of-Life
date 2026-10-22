#include "simulation.h"
#include "rules.h"

Simulation::Simulation(Grid &initial):
	current(initial),
	next(initial),
	generation_cnt(0)
{
}

const Grid& Simulation::grid() const
{
	return current;
}
void Simulation::step()
{
	for (int r = 0; r < current.rows(); r++)
	{
		for (int c = 0; c < current.cols(); c++)
		{
			int alive = current.count_live_neighbours(r, c);
			next.set(r, c,Rules::next_state(current.get(r,c),alive));
		}
	}
	current = next;
	generation_cnt++;
}

int Simulation::generation() const
{
	return generation_cnt;
}