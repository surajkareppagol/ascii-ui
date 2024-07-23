/**
 * @file components.h
 * @author Suraj K
 *
 * @brief Header file
 *
 * @date 2024-07-21
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef _COMPONENTS_H_
#define _COMPONENTS_H_

#include <ctype.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* MACROS */

#define MAX_BUFFER_SIZE 40

#define clear_screen_s() printf("\033[2J")
#define clear_screen() printf("\033[3J")
#define cursor_home() printf("\033[H")

#define FG_START_COLOR_VALUE 30
#define BG_START_COLOR_VALUE 40

/* ENUMS */

enum Color {black = 0, red, green, yellow, blue, magenta, cyan, white, current, reset};

/* FUNCTIONS */

/* For colors.c */
void set_bg_color(uint color);
void set_fg_color(uint color);
void set_color(uint fg, uint bg);

/* For panel.c */
void build_panel(char *panel_edges, char *message, uint pos);
void place_panel(char *message, char align);

/* For signals.c */
void handle_signal(void (*clean) (int));

/* For term.c */
void cursor_move(uint row, uint column);
void cursor_up_down(uint rows, char direction);
void cursor_left_right(uint columns, char direction);
void get_term_wh(uint *rows, uint *columns);

void clean_up(int sig_value);

/* For text.c */
void mv_print(char *message, uint rows, uint columns);
void center_print(char *message, uint rows);

/* For util.c */
void fill_characters(char *dest, char character, uint size);
uint get_center_pos(uint size);
uint get_right_pos(uint size);
int check_wh(uint rows, uint columns);
void get_cursor_pos(uint *current_row, uint *current_column);
void clear_line(uint rows);

#endif
