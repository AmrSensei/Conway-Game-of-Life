#pragma once

namespace Terminal
{
	bool enable_ansi();
	void clear_screen();
	void cursor_top();
	void hide_cursor();
	void show_cursor();
	void sleep_ms(int milliseconds);
}