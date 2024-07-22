/**
 * @file panel.c
 * @author Suraj K
 *
 * @brief Functions to build various components 
 *
 * @date 2024-07-21
 * 
 * @copyright Copyright (c) 2024
 */

#include "components.h"

/**
 * @brief Build panel using panel edges and message
 * 
 * @param panel_edges The panel edges
 * @param message The message to be printed inside panel
 * @param pos Position of the panel
 *
 * @return void
 */
void build_panel(char *panel_edges, char *message, uint pos)
{
  /* Build panel */
  cursor_left_right(pos, 'r');
  printf("%s\n", panel_edges);

  cursor_left_right(pos, 'r');
  printf("| %s |\n", message);
  
  cursor_left_right(pos, 'r');
  printf("%s\n", panel_edges);
}

/**
 * @brief Place panel based on the align value
 *
 * @param message The message to be printed inside the panel 
 * @param align The alignment value, either 'r', 'c', 'l' 
 *
 * @return void
 */
void place_panel(char *message, char align)
{
  uint message_size = strlen(message);

  /* | HELLO | => 4 + 1 null character + 1 newline */
  uint panel_edge_size = message_size + 5;
  char *panel_edges = calloc(panel_edge_size, sizeof(char));

  /* Check for NULL pointer */
  if (panel_edges == NULL) {
    perror("Error (place_panel)");
    return;
  }

  fill_characters(panel_edges, '=', panel_edge_size - 1);
  panel_edges[panel_edge_size - 1] = '\0';

  /* Place panel according to the align property */
  if (align == 'c') {
    
    int start_pos = get_center_pos(panel_edge_size);
    build_panel(panel_edges, message, start_pos);

  } else if (align == 'l') {
    
    build_panel(panel_edges, message, 0);
  
  } else if (align == 'r') {

    int right_pos = get_right_pos(panel_edge_size);
    build_panel(panel_edges, message, right_pos);
  
  }
    
  free(panel_edges);
}
