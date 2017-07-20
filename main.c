#include "draw.h"

int main(int argc, char **argv)
{
	setup_echo();
	clear();
	print_chat();
	usleep(DURATION*10);
 	endwin();
	return 0;
}
