#include "components.h"

/**
 * @brief Set background color
 *
 * @param color The color to be used as background color
 *        look into components.h for possible colors
 *
 * @return void
 */
void set_bg_color(uint color) {
  uint bg_color = BG_START_COLOR_VALUE + color;
  printf("\033[%dm", bg_color);
}

/**
 * @brief Set foreground color
 *
 * @param color The color to be used as background color
 *        look into components.h for possible colors
 *
 * @return void
 */
void set_fg_color(uint color) {
  uint fg_color = FG_START_COLOR_VALUE + color;
  printf("\033[%dm", fg_color);
}

/**
 * @brief Set both foreground and background colors
 *
 * @param fg The foreground color
 * @param bg The background color
 *
 * @return void
 */
void set_color(uint fg, uint bg) {
  uint fg_color = FG_START_COLOR_VALUE + fg;
  printf("\033[%dm", fg_color);

  uint bg_color = BG_START_COLOR_VALUE + bg;
  printf("\033[%dm", bg_color);
}