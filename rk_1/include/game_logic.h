#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include "timer.h"

typedef struct
{
    WINDOW *input;
    WINDOW *status;
} cur_w;

cur_w *game_init(void);
void game_loop(cur_w *wins);