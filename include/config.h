#pragma once
#include<string_view>
namespace constants 
{
	inline constexpr int ROWS = 20;
	inline constexpr bool WrapAround = true;
	inline constexpr int COLS = 40;
	inline constexpr int GENERATIONS = 100;
	inline constexpr int FRAME_DELAY_MS = 130;
	/*
	*	you can change how the alive and dead glyphs would look to a couple of things
	*		1. you can change it to the letter O.
	*		2. you can change it to ## and the dead one to two spaces.
	*		3. you can change it to \033[42m  \033[0m which would change the block color to green
	*		4. you can change it to the full UNICODE block ██.
	*		5. you can change the dead one to \033[40m  \033[0m which would make it black
	*		6. or you can change the dead one to \033[40m  \033[0m which would it make it gray.
	*/  
	inline constexpr std::string_view ALIVE_GLYPH = "\033[42m  \033[0m";
	inline constexpr std::string_view DEAD_GLYPH = "\033[40m  \033[0m";
}