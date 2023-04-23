#include "text_loader.h"

int text_to_lines(const char path_to_file[], int max_x, char out[128][MAX_WIDTH]) {
    
        FILE *fp;
        fp = fopen(path_to_file, "r");
        if (fp == NULL)
        {
            return 1;
        }

        int line_counter = 0;
        char lines[MAX_LINES][max_x];

        char line[max_x];

        int word_len = 0;
        char word[max_x];

        for (int i=0; i < MAX_LINES; ++i) {
            for (int j=0; j < max_x; ++j) {
                lines[i][j] = '\0';
            }
        }

        for (int i = 0; i < max_x; ++i) {
            line[i] = '\0';
            word[i] = '\0';
        }

        char *read_line = NULL;
        size_t len = 0;
        ssize_t read;

        int new_line_found = 0;
        
        int t_sym = 0;
        while ((read = getline(&read_line, &len, fp)) != -1) {
            int sym = 0;
            while(1) {
                if (read_line[sym] == '\0') {
                    break;
                }
                if (read_line[sym] == '\n') {
                    new_line_found = 1;
                }
                if (read_line[sym] == ' ') {
                    word[word_len] = ' ';
                    if (word_len + t_sym + 1 > max_x-1 ) {
                        line[max_x-1] = '\0';
                        strcpy(lines[line_counter], line);
                        line_counter++;
                        if (new_line_found) {
                            line_counter++;
                            new_line_found = 0;
                        }   
                        memset(line, 0, strlen(line));
                        t_sym = 0;
                    }
                    strcat(line, word);
                    t_sym += word_len + 1;
                    word_len = 0;
                    memset(word, 0, strlen(word));
                    sym++;
                    
                } else {
                    if (read_line[sym] != '\n') {
                        word[word_len] = read_line[sym];
                    } else {
                        word[word_len] = ' ';
                    }
                    word_len++;
                    sym++;
                }
                
            }
        }
        for(int i=0; i<MAX_LINES; i++) {
            strcpy(out[i], lines[i]);
        }
        return 0;
    //}
}