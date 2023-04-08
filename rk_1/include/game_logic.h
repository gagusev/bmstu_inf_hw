#include <ncurses.h>
#include <stdlib.h>
#include "timer.h"
#include "text_loader.h"

typedef struct
{
    WINDOW *input;
    WINDOW *status;
} cur_w;

void game_init(void);