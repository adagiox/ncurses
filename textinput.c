#include "draw.h"

int read_print_pos(int y, int x)
{
	char *str = ft_strnew(getmaxx(stdscr));
	move(getmaxy(stdscr), 0);
	getnstr(str, getmaxx(stdscr));
	mvprintw(y, x, str);
	return 1;
}

// Function to move back to previous cursor location

// Function to echo at a position

// Function to delete character and move cursor back

int read_echo_pos(int y, int x)
{
	char ch;
	int prow, pcol;
	int row = y;
	int col = x;
	getyx(stdscr, prow, pcol);
	while ((ch = getch()) != 10)
	{
		if (ch == 8 && col > 0)
		{
			delch();
			col--;
		}
		mvaddch(row, col, ch);
		move(prow, pcol);
		refresh();
	}
	return 1;
}
