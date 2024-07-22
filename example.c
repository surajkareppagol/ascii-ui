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

int main()
{   
  handle_signal(clean_up);
  clear_screen_s();

  uint number_a = 1, number_b = 1;

  char choice = 'y', buffer[40];

  while (1) {
    clear_screen();
    cursor_home();

    place_panel("ASCII - UI % A C Library", 'c');

    mv_print("I will add and print \"two\" numbers you give, try it.\n", 8, 0);
    scanf("%u%u", &number_a, &number_b);
    clear_line(9);
    
    clear_line(12);
    snprintf(buffer, 40, "The addition is %d. Am i right?\n", add(number_a, number_b));
    center_print(buffer, 12);

    mv_print("Continue (y/n)?", 14, 0);
    scanf("%c", &choice);
    clear_line(15);
    
    if (choice == 'n') {
      break;
    }
  }

  return 0;
}

int add(int number_a, int number_b)
{
  return number_a + number_b;
}