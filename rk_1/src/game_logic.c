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

    mvwprintw(new->input, 1, 1, "Additionally, curses provides some special characters for character-based graphics. You can draw tables, horizontal or vertical lines, etc. You can find all avaliable characters in the header file ncurses.h. Try looking for macros beginning with ACS_ in this file.");
    wrefresh(new->input);
    mvwprintw(new->status, 1, 1, "Time: 00:00");
    wrefresh(new->status);

    return new;
}

void game_loop(cur_w *wins) {

    clock_t t = countdown_init(10);

    while(1) {
        
        countdown *c = countdown_update(t);
        mvwprintw(wins->status, 1, 1, "Time: %02d:%02d", c->mins, c->secs);
        wrefresh(wins->status);
        if (c->mils == 0) {
            endwin();
            exit(0);
        }
    }
}