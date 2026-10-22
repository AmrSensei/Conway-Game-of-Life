#include <iostream>
#include "config.h"
#include "grid.h"
#include "renderer.h"
#include "patterns.h"
#include "rules.h"
#include "terminal.h"
#include "simulation.h"
#include "run.h"
#include "random.h"
namespace Run
{
	std::string get_title()
	{
		size_t target_width = 2 * constants::COLS;
		std::string title_text = "\033[1;33mConway's Game Of Life\033[0m";
		std::string title;
		if (title_text.length() < target_width)
		{
			size_t padding = (target_width - title_text.length()) / 2;
			title.append(padding, ' ');
		}
		title += title_text;
		title.resize(target_width, ' ');
		title += '\n';
		std::string separator(target_width, '=');
		title += separator;
		title += '\n';
		return title;
	}
	void run()
	{
		// prompting the user.
		Terminal::enable_ansi();
		int rows = constants::ROWS;
		int cols = constants::COLS;
		int gen = constants::GENERATIONS;
		char wraparound = constants::WrapAround == true ? 'y' : 'n';
		std::cout << get_title();
		std::cout << "Enter rows (Defult : " << constants::ROWS << " ) : ";
		std::cin >> rows;
		std::cout << "Enter columns (Defult : " << constants::COLS << " ) : ";
		std::cin >> cols;
		std::cout << "Enter the number of Generations you want (Defult : " << constants::GENERATIONS << " ) : ";
		std::cin >> gen;
		std::cout << "Enable Wrap-around boundaries y/n ? (Defult : " << (constants::WrapAround ? "y":"n") << " ) : ";
		std::cin >> wraparound;
		bool WrapAround = wraparound == 'y' || wraparound == 'Y' ? true : false;

		// clear terminal and hide crusor.
		Terminal::clear_screen();
		Terminal::hide_cursor();

		// initialize and simulate.
		Grid g(rows,cols,WrapAround);
		Random::fill_random(g, 0.26);
		//Patterns::place_lightweight_spaceship(g, 10, 10);
		Simulation s(g);
		Renderer r(constants::ALIVE_GLYPH, constants::DEAD_GLYPH);
		for (int i = 0; i <= gen; i++)
		{
			Terminal::cursor_top();
			std::cout << r.build_frame(s.grid(), s.generation());
			Terminal::sleep_ms(constants::FRAME_DELAY_MS);
			if (i < gen) s.step();
		}
		Terminal::show_cursor();
		std::cout << '\n';
		std::cout << "GAME OVER!";
	}
}