/**
 * @file term.c
 * @author Suraj K
 *
 * @brief Terminal routine functions 
 *
 * @date 2024-07-21
 * 
 * @copyright Copyright (c) 2024
 */

#include <sys/ioctl.h>

#include "components.h"

/**
 * @brief Move cursor to specified position 
 * 
 * @param column The column position
 *
 * @return void
 */
void cursor_move(uint row, uint column)
{
  printf("\033[%u;%uH", row, column);
}

/**
 * @brief Get the terminal width and height
 * 
 * @param *rows The pointer to save the number of rows
 * @param *columns The pointer to save the number of columns
 *
 * @return void
 */
void get_term_wh(uint *rows, uint *columns)
{
  struct winsize term;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &term);

  *rows = term.ws_row;
  *columns = term.ws_col;
}

/**
 * @brief Default clean up function for SIGINT 
 * 
 * @param sig_value The value passed by signal()
 *
 * @return void
 */
void clean_up(int sig_value)
{
  clear_screen();
  cursor_home();

  exit(EXIT_SUCCESS);
}

/**
 * @brief Move cursor to up or down based on direction value 
 * 
 * @param rows The rows position
 * @param direction The direction, 'u' or 'd'
 *
 * @return void
 */
void cursor_up_down(uint rows, char direction)
{
  (direction == 'u') ?
  (printf("\033[%uA", rows)) :
  (direction == 'd') ?
  (printf("\033[%uB", rows)) :
  1;
}

/**
 * @brief Move cursor to left or right based on direction value 
 * 
 * @param columns The columns position
 * @param direction The direction, 'l' or 'r'
 *
 * @return void
 */
void cursor_left_right(uint columns, char direction)
{
  (direction == 'l') ?
  (printf("\033[%uD", columns)) :
  (direction == 'r') ?
  (printf("\033[%uC", columns)) :
  1;
}
