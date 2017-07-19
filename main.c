#include "draw.h"

int main(int argc, char **argv)
{
	setup_echo();
	read_echo_pos(getmaxy(stdscr) - 2, 10);
	usleep(DURATION * 10);
	exit_screen();
	return 1;
}
