#include "game_logic.h"

cur_w *game_init(void) {
    initscr();

    int width, height;
    getmaxyx(stdscr, height, width);

    cur_w *new = malloc(sizeof *new);

    new->input = newwin(height-3, width, 0, 0);
    new->status = newwin(3, width, height-3, 0);

    refresh();

    box(new->input, 0, 0);
    box(new->status, 0, 0);

    char check[128][MAX_WIDTH];	
    text_to_lines("./sample_texts/lorem.txt", width-2, check);
    for (int i = 1; i < height-4; ++i) {
        mvwprintw(new->input, i, 1, "%s", check[i-1]);
        wrefresh(new->input);
    }

    wrefresh(new->input);
    mvwprintw(new->status, 1, 1, "Time: 00:00");
    wrefresh(new->status);

    return new;
}

void game_loop(cur_w *wins) {

    clock_t t = countdown_init(100);

    while(1) {
        
        countdown *c = countdown_update(t);
        mvwprintw(wins->status, 1, 1, "Time: %02d:%02d", c->mins, c->secs);
        wrefresh(wins->status);
        if (c->mils < 100) {
            endwin();
            exit(0);
        }
    }
}