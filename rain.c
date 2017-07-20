#include "draw.h"

int rain()
{
	for (int i = 0; i < getmaxy(stdscr); i++)
	{
		for (int j = 0; j < getmaxx(stdscr); j++)
		{
			mvprintw(i, j, "*");
			refresh();
		}
		usleep(DURATION);
	}
	return 1;
}
