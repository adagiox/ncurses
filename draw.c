#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

#define DURATION 60000

int screen_setup()
{
	initscr();
 	noecho();
 	curs_set(FALSE);
	raw();
	keypad(stdscr, TRUE);
	return 1;
}

void exit_screen()
{
	endwin();
	exit(0);
}

int key_input(int *x, int *y)
{
	if (getch() == KEY_LEFT)
	{
		*x--;
	}
	else if (getch() == KEY_RIGHT)
	{
		*x++;
	}
	else if (getch() == KEY_UP)
	{
		*y--;
	}
	else if (getch() == KEY_DOWN)
	{
		*y++;
	}
	return 1;
}

int print_text(int x, int y, char *str)
{
	mvprintw(x, y, str);
	refresh();
	return 1;
}

int print_move_text(char *str)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		clear();
		timeout(3000);
		int c = getch();
		switch(c)
		{
			case KEY_ENTER:
				exit_screen();
				break;
			case KEY_UP:
				y--;
				break;
			case KEY_DOWN:
				y++;
				break;
			case KEY_LEFT:
				x--;
				break;
			case KEY_RIGHT:
				x++;
				break;
		}
		mvprintw(y, x, str);
		refresh();
		usleep(DURATION);
	}
	return 1;
}

int print_scroll_top(int y, char *str)
{
	int j = getmaxx(stdscr);
	while (y < j)
	{
		clear();
		mvprintw(0, y, str);
		refresh();
		usleep(DURATION);
		y++;
	}
	return 1;
}

int print_scroll_top_bot(int y, int x, char *str)
{
	int j = getmaxy(stdscr);
	while (y < j)
	{
		clear();
		mvprintw(y, x, str);
		refresh();
		usleep(DURATION);
		y++;
	}
	return 1;
}

int print_scroll_top_bot_bounce(int y, int x, char *str)
{
	int j = getmaxy(stdscr);
	while (1)
	{
		while (y < j)
		{
			clear();
			mvprintw(y, x, str);
			refresh();
			usleep(DURATION);
			y++;
		}
		while (y > 0)
		{
			clear();
			mvprintw(y, x, str);
			refresh();
			usleep(DURATION);
			y--;
		}
		if (getch() == KEY_LEFT)
		{
			x--;
		}
		else if (getch() == KEY_RIGHT)
		{
			x++;
		}
	}
	return 1;
}

int print_scroll_all(int y, char *str)
{
	int j = getmaxx(stdscr) - strlen(str);
	while (y < j)
	{
		clear();
		for (int i = 0; i < getmaxy(stdscr); i++)
			mvprintw(i, y, str);
		refresh();
		usleep(DURATION);
		y++;
	}
	return 1;
}

int main()
{
	screen_setup();
	char *str = "*";
	print_move_text(str);

 	endwin();
	return 0;
}
