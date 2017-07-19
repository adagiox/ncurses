#include "draw.h"

int read_echo_pos(int y, int x)
{
	char *str = ft_strnew(getmaxx(stdscr));
	move(getmaxy(stdscr), 0);
	getnstr(str, getmaxx(stdscr));
	mvprintw(y, x, str);
	return 1;
}
