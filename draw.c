#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "libft/libft.h"

#define DURATION 120000

int screen_setup()
{
	initscr();
 	noecho();
 	curs_set(FALSE);
	//raw();
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

int print_grid()
{
	clear();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	for (int j = 1; j < getmaxy(stdscr); j++)
	{
		int x = 3;
		for (int i = 1; i < getmaxy(stdscr); i++)
		{
			move(0, x);
			printw(ft_itoa(i));
			if (i > 9 && i < 100)
				x += 4;
			else
				x += 3;
			mvprintw(j, 2, "|");
		}
		mvprintw(j, 0, ft_itoa(j));
	}
	refresh();
	attroff(COLOR_PAIR(1));
	return 1;
}

char *scroll_left(char *str)
{
	char *temp = ft_strnew(ft_strlen(str));
	char save = str[0];
	temp = ft_strcpy(temp, &str[1]);
	temp[ft_strlen(str) - 1] = save;
	return temp;
}

char *scroll_right(char *str)
{
	char *temp = (char *)malloc(sizeof(char) * strlen(str) + 1);
	char save = str[0];
	int i = 1;
	while (i < strlen(str))
	{
		temp[i - 1] = str[i];
		i++;
	}
	temp[i] = save;
	temp[i + 1] = 0;
	return temp;
}

int print_scroll_left(int y, int x, char **str)
{
	clear();
	mvprintw(y, x, *str);
	usleep(DURATION);
	refresh();
	*str = scroll_left(*str);
	return 1;
}

int print_scroll_right(int y, int x, char *str)
{
	mvprintw(y, x, scroll_right(str));
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
		timeout(1);
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
				x--;
				break;
			case KEY_RIGHT:
				x++;
				x++;
				break;
		}
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

// int main(int argc, char **argv)
// {
// 	screen_setup();
// 	char *str = argv[1];
// 	int div = getmaxy(stdscr) / ft_strlen(str);
// 	while (1)
// 	{
// 		for (int i = 0; i < getmaxy(stdscr); i++)
// 		{
// 			for (int j = 0; j < getmaxy(stdscr); j += div)
// 			{
// 				// while(1)
// 				// {
// 				// 	mvprintw(30, 30, ft_itoa(div));
// 				// 	usleep(DURATION);
// 				// }
// 				print_scroll_left(i, j, &str);
// 			}
// 		}
// 	}
//  	endwin();
// 	return 0;
// }

int main(int argc, char **argv)
{
	screen_setup();
	char *str = argv[1];
	print_grid();
	usleep(DURATION * 50);
 	endwin();
	return 0;
}
