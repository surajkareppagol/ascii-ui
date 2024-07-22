# ASCII UI

`ASCII UI` is a small c library which could be used to create small `ASCII
User Interfaces`. It uses ANSI escape sequences that control the terminal.

For example moving cursor, coloring text and others. Not many terminals
support these sequences so it might not work on all terminals. This is
being developed with gnome terminal with `Version 3.44.0 for GNOME 42`.

The doxygen comments have been added to the functions and all the files,
it will give more info on what each function does.

Use `make` command to build the executable.

> Currently adding color support to this.

## Example

This is the result for below code.

![ascii-ui](https://raw.githubusercontent.com/surajkareppagol/Assets/main/35-ascii-ui/ascii-ui.gif)

---

```c
#include "src/components.h"

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
```
