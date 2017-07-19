#ifndef DRAW_H
#define DRAW_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "libft/libft.h"

#define DURATION 120000

int setup();
int setup_echo();
int exit_screen();
int print_text(int x, int y, char *str);
int print_grid();
char *scroll_left(char *str);
char *scroll_right(char *str);
int print_scroll_left(int y, int x, char **str);
int print_scroll_right(int y, int x, char **str);
int print_move_text(char *str);
int print_scroll_top(int y, char *str);

int read_echo_pos(int y, int x);

#endif
