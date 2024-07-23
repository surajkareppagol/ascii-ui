/**
 * @file util.c
 * @author Suraj K
 *
 * @brief Provides utility functions
 *
 * @date 2024-07-21
 *
 * @copyright Copyright (c) 2024
 */

#include "components.h"

/**
 * @brief Fill dest with character.
 *
 * @param dest The buffer to fill characters
 * @param character The characters
 * @param size The number of characters
 *
 * @return void
 */
void fill_characters(char *dest, char character, uint size) {
  if (dest == NULL) {
    return;
  }

  for (int i = 0; i < size; i++) {
    *(dest + i) = character;
  }
}

/**
 * @brief Get the center position of the component
 *
 * @param size The size of the component
 *
 * @return uint
 */
uint get_center_pos(uint size) {
  uint term_rows, term_cols;

  get_term_wh(&term_rows, &term_cols);

  uint center_term_pos = term_cols / 2;
  uint center_pos = size / 2;

  return (center_term_pos - center_pos);
}

/**
 * @brief Get the right position of the component
 *
 * @param size The size of the component
 *
 * @return uint
 */
uint get_right_pos(uint size) {
  uint term_rows, term_cols;

  get_term_wh(&term_rows, &term_cols);

  return (term_cols - size);
}

/**
 * @brief Check rows and columns whether they are
 * within bounds
 *
 * @param rows The row value
 * @param columns The column value
 *
 * @return int
 */
int check_wh(uint rows, uint columns) {
  uint term_rows, term_cols;

  get_term_wh(&term_rows, &term_cols);

  if (rows <= term_rows && columns <= term_cols) {
    return 0;
  } else {
    return 1;
  }
}

/**
 * @brief Get the current cursor position
 * NOTE: [WIP] This function is not yet completed.
 *
 * @param current_row The pointer to store current row position
 * @param current_column The pointer to store current column position
 *
 * @return void
 */
void get_cursor_pos(uint *current_row, uint *current_column) {
  char cursor_position[MAX_BUFFER_SIZE];
  printf("\033[6n");

  fgets(cursor_position, MAX_BUFFER_SIZE, stdin);

  char rc_size[10];
  uint buffer_index = 0;

  for (int i = 0; *(cursor_position + i) != '\0'; i++) {

    /* ^[[11;1R - From \033[6n */
    if (*(cursor_position + i) == ';') {
      rc_size[buffer_index] = '\0';
      *current_row = atoi(rc_size);
      buffer_index = 0;
      continue;
    }

    if (*(cursor_position + i) == 'R') {
      rc_size[buffer_index] = '\0';
      *current_column = atoi(rc_size);
      buffer_index = 0;
      break;
    }

    if (isdigit(*(cursor_position + i))) {
      rc_size[buffer_index] = *(cursor_position + i);
      buffer_index += 1;
    }
  }
}

/**
 * @brief Clear the entire line.
 *
 * @param rows The line number to clear
 *
 * @return void
 */
void clear_line(uint rows) {
  cursor_move(rows, 0);
  printf("\033[2K");
}