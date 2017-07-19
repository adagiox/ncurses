#include "draw.h"

int main(int argc, char **argv)
{
	setup();
	char *str = argv[1];
	char *cpy = ft_strdup(str);
	while (1)
	{
		for (int j = 0; j < getmaxy(stdscr); j+=2)
		{
			for (int i = 0; i < 50; i++)
			{
				print_text(j, 0, str);
				print_text(j + 1, 0, cpy);
			}
		}
		str = scroll_left(str);
		cpy = scroll_right(cpy);
		refresh();
		usleep(DURATION);
	}
	usleep(DURATION * 50);
 	endwin();
	return 0;
}
