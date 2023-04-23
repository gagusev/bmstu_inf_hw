#include "game_logic.h"

void game_init(void) {
    initscr();

    start_color();	

    noecho();

    halfdelay(1);

    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_RED);

    int width, height;
    getmaxyx(stdscr, height, width);

    cur_w *new = malloc(sizeof *new);

    new->input = newwin(height-3, width, 0, 0);
    new->status = newwin(3, width, height-3, 0);

    refresh();

    box(new->input, 0, 0);
    box(new->status, 0, 0);

    char text[128][MAX_WIDTH];	
    text_to_lines("./sample_texts/lorem.txt", width-2, text);
    for (int i = 1; i < height-4; ++i) {
        mvwprintw(new->input, i, 1, "%s", text[i-1]);
        wrefresh(new->input);
    }

    wrefresh(new->input);
    mvwprintw(new->status, 1, 1, "Time: 00:00");
    wrefresh(new->status);

    int t = countdown_init(100);

    int char_row = 0;
    int char_col = 0;

    while(1) {

        countdown *cnt = countdown_update(t);
        
        mvwprintw(new->status, 1, 1, "Time: %02d:%02d", cnt->mins, cnt->secs);

        if (cnt->secs < 1 && cnt->mins == 0) {
            endwin();
            exit(0);
        }

        if (text[char_row][char_col] == '\0') {
            char_col = 0;
            char_row++;
        }
        
        char c = getch();
        
        if (c == text[char_row][char_col]) {
            wattron(new->input, COLOR_PAIR(1));
            mvwprintw(new->input, char_row+1, char_col+1, "%c", c);
            wattroff(new->input, COLOR_PAIR(1));

            char_col++;
        } else if (c != EOF) {
            wattron(new->input, COLOR_PAIR(2));
            mvwprintw(new->input, char_row+1, char_col+1, "%c", text[char_row][char_col]);
            wattroff(new->input, COLOR_PAIR(2));

            char_col++;
        }

        wmove(new->input, char_row+1, char_col+1);
        wrefresh(new->status);
        wrefresh(new->input);

    }
}