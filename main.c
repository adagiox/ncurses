#include "draw.h"

int main(int argc, char **argv)
{
	setup_echo();
	move(0, 0);
	char *str = argv[1];
	clear();
	read_echo_pos(getmaxy(stdscr) - 1, 0);
	usleep(DURATION);
 	endwin();
	return 0;
}
