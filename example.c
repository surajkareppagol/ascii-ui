/**
 * @file example.c
 * @author Suraj K
 *
 * @brief Example file using the ascii-ui functions
 *
 * example.c uses the ascii-ui functions to showcase
 * some its capabilities.
 *
 * stdio.h is already included in the components.h
 * header file.
 *
 * @date 2024-07-21
 *
 * @copyright Copyright (c) 2024
 */

#include "src/components.h"
#include <stdio.h>

int add(int number_a, int number_b);
int subtract(int number_a, int number_b);
int multiply(int number_a, int number_b);
int divide(int number_a, int number_b);
int perform(int number_a, int number_b, char operation);

int main() {
  handle_signal(clean_up);
  clear_screen_s();

  uint number_a = 1, number_b = 1;

  char operation = '+', choice = 'y', buffer[40];

  while (1) {
    clear_screen();
    cursor_home();

    /* Set color */
    set_color(black, white);

    place_panel("ASCII - UI % A C Library", 'c');

    /* Set color */
    set_color(black, green);

    /* Move and print */
    mv_print("I can do arithmetic operation on \"two\" numbers you give, try "
             "it. (1 + 1): ",
             8, 10);
    scanf("%u%c%u", &number_a, &operation, &number_b);

    /* Clear line for scanf */
    clear_line(8);

    clear_line(12);
    /* Set color */
    set_color(black, blue);

    snprintf(buffer, 40, "The addition is %d. Am i right?\n",
             perform(number_a, number_b, operation));
    center_print(buffer, 12);

    /* Set fg color */
    // set_fg_color(yellow);

    /* Move and print */
    mv_print("Continue (y/n)?", 14, 0);
    scanf("%c", &choice);
    clear_line(15);

    if (choice == 'n') {
      break;
    }
  }

  return 0;
}

int add(int number_a, int number_b) { return number_a + number_b; }

int subtract(int number_a, int number_b) { return number_a - number_b; }

int multiply(int number_a, int number_b) { return number_a * number_b; }

int divide(int number_a, int number_b) { return number_a / number_b; }

int perform(int number_a, int number_b, char operation) {
  switch (operation) {
  case '+':
    return add(number_a, number_b);
  case '-':
    return subtract(number_a, number_b);
  case '*':
    return multiply(number_a, number_b);
  case '/':
    return divide(number_a, number_b);
  }

  return 0;
}