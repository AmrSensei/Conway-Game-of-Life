#include "random.h"
#include <random>
namespace Random
{
    namespace
    {
        std::mt19937& get_engine()
        {
            static std::mt19937 mt{ std::random_device{}() };
            return mt;
        }
    }
	void fill_random(Grid& g, double living_prob)
	{
        std::bernoulli_distribution dist(living_prob);
        auto& mt = get_engine();

        for (int r = 0; r < g.rows(); ++r)
        {
            for (int c = 0; c < g.cols(); ++c)
            {
                if (dist(mt))
                {
                    g.set(r, c, Cell::Alive);
                }
                else
                {
                    g.set(r, c, Cell::Dead);
                }
            }
        }
	}
}