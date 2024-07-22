/**
 * @file signals.c
 * @author Suraj K
 *
 * @brief Functions to capture signals
 *
 * @date 2024-07-21
 * 
 * @copyright Copyright (c) 2024
 */


#include <signal.h>

#include "components.h"

/**
 * @brief Wrapper around signal() function 
 * 
 * @param *clean A function pointer
 *
 * @return void
 */
void handle_signal(void (*clean) (int))
{
  signal(SIGINT, clean);
}
