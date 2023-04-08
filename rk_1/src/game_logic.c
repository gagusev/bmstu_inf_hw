#include "game_logic.h"

void game_init(void) {
    initscr();

    noecho();

    delauy

    start_color();	

    init_pair(1, COLOR_GREEN, COLOR_BLACK);

    

    int width, height;
    getmaxyx(stdscr, height, width);

    cur_w *new = malloc(sizeof *new);

    new->input = newwin(height-3, width, 0, 0);
    new->status = newwin(3, width, height-3, 0);

    refresh();

    box(new->input, 0, 0);
    box(new->status, 0, 0);

    char text[128][MAX_WIDTH];	
    text_to_lines("../sample_texts/lorem.txt", width-2, text);
    for (int i = 1; i < height-4; ++i) {
        mvwprintw(new->input, i, 1, "%s", text[i-1]);
        wrefresh(new->input);
    }

    wrefresh(new->input);
    mvwprintw(new->status, 1, 1, "Time: 00:00");
    wrefresh(new->status);

    clock_t t = countdown_init(100);

    int char_row = 0;
    int char_col = 0;

    while(1) {

        if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}

        char c = getch();
        
        countdown *cnt = countdown_update(t);
        wattron(new->status, COLOR_PAIR(1));
        mvwprintw(new->status, 1, 1, "Time: %02d:%02d", cnt->mins, cnt->mils);
        wattroff(new->status, COLOR_PAIR(1));
        wrefresh(new->status);
        refresh();
        if (cnt->mils < 100) {
            endwin();
            exit(0);
        }
        
        
        
        //if (c == text[char_row][char_col]) {
            //mvwprintw(new->input, char_row+1, char_col+1, "%c", c);
            
            //char_col++;
        //}

        
    }
}