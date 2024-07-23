# ASCII UI

`ASCII UI` is a small c library which could be used to create small `ASCII
User Interfaces`. It uses ANSI escape sequences that control the terminal.

For example moving cursor, coloring text and others. Not many terminals
support these sequences so it might not work on all terminals. This is
being developed with gnome terminal with `Version 3.44.0 for GNOME 42`.

The doxygen comments have been added to the functions and all the files,
it will give more info on what each function does.

Use `make` command to build the executable.

> Currently creating more components such as tables.

## Example

This is the result for below code.

![ascii-ui](https://raw.githubusercontent.com/surajkareppagol/Assets/main/35-ascii-ui/ascii-ui.gif)

---

```c
#include "src/components.h"

int main()
{
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
    mv_print("I can do arithmetic operation on \"two\" numbers you give, try it. (1 + 1): ", 8, 10);
    scanf("%u%c%u", &number_a, &operation, &number_b);

    /* Clear line for scanf */
    clear_line(8);

    clear_line(12);
    /* Set color */
    set_color(black, blue);

    snprintf(buffer, 40, "The addition is %d. Am i right?\n", perform(number_a, number_b, operation));
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
```
