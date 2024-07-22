/**
 * @file text.c
 * @author Suraj K
 *
 * @brief Functions to print text
 *
 * @date 2024-07-21
 * 
 * @copyright Copyright (c) 2024
 */

#include "components.h"

/**
 * @brief Move cursor and print 
 *
 * @param message The message to be printed 
 * @param rows The row position
 * @param columns The column position
 *
 * @return void
 */
void mv_print(char *message, uint rows, uint columns)
{
  if (check_wh(rows, columns) != 0) {
    return;
  }

  cursor_home();
  cursor_move(rows, columns);
  printf("%s", message);
}

/**
 * @brief Move cursor to center and print 
 *
 * @param message The message to be printed 
 * @param rows The row position
 *
 * @return void
 */
void center_print(char *message, uint rows)
{
  if (check_wh(rows, 0) != 0) {
    return;
  }

  uint message_size = strlen(message);
  uint center_pos = get_center_pos(message_size);

  cursor_home();
  cursor_move(rows, center_pos);
  printf("%s", message);
}
