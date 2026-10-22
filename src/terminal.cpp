#include <iostream>
#include "terminal.h"
#include <thread>    // For std::this_thread::sleep_for
#include <chrono>    // For units (like ms)
// Windows.h would crash if run on anything other than windows
#ifdef _WIN32
#include <Windows.h>
#endif
namespace Terminal
{
	bool enable_ansi()
	{
		// windows specific part to enable windows terminal escape codes.
#ifdef _WIN32
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hOut == INVALID_HANDLE_VALUE) return false;

		DWORD mode = 0;
		if (!GetConsoleMode(hOut, &mode)) return false;

		mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		if (!SetConsoleMode(hOut, mode)) return false;
		// to make widnows render the ██ correctly.
		SetConsoleOutputCP(CP_UTF8);
#endif
		return true;
	}

	void clear_screen()
	{
		// cleaer the screen then move the cursor to top left.
		std::cout << "\033[2J";
		std::cout << "\033[H";
	}
	void cursor_top()
	{
		// move the cursor to top left.
		std::cout << "\033[H";
	}
	void sleep_ms(int milliseconds)
	{
		//using namespace std::chrono_literals;
		std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
	}
	void hide_cursor()
	{
		std::cout << "\033[?25l";
	}

	void show_cursor()
	{
		std::cout << "\033[?25h";
	}
}