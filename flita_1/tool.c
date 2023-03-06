#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

void throw_help() {
    puts("\nSo here are the examples of usage:\n");
    puts("SAVE <your set> AS <name of set> – Will write your set to the database;");
    puts("SHOW <name of set> AS [BIN/DEC] – Will print out your set from the database;");
    puts("UNITE <name of set> WITH <name of set> – Will unite two sets from the database;");
    puts("HELP or -h or -help – Will show this message again;\n");
}

int bin_to_dec(char bin[]) {
    int dec = 0;
    for (int j = strlen(bin)-1; j >= 0; --j) {
        dec += (bin[j] - '0') * pow(2, strlen(bin)-j-1);
    }
    return dec;
}

int dec_to_bin(int dec) {
    int bin = 0;
    char a[32];
    int size = 0;
    for(int i=0; dec > 0; ++i) {    
        a[i] = dec % 2;    
        dec = dec / 2;
        size++;
    }
    for (int i=0; i < size; ++i) {
        bin += a[i] * pow(10, i);
    }
    return bin;
}

int is_member(int new, int set[], int set_size) {
    for (int i=0; i < set_size; ++i) {
        if (set[i] == new) {
            return 1;
        }
    }
    return 0;
}

int set_exists(char name[]) {
    FILE *fp;
    fp = fopen("db.txt", "r");
    if (fp == NULL) {
        return 0;
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        int found = 1;
        int i = 0;
        while(line[i] != ' ') {
            if (line[i] != name[i]) {
                found = 0;
            }
            i++;
        }
        if (found) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int read_line(char name[], int nums[]) {
    FILE *fp;
    fp = fopen("db.txt", "r");
    if (fp == NULL) {
        puts("ERROR: File writing operation failed");
        exit(1);
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int nums_size = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
        int found = 1;
        int i = 0;
        while(line[i] != ' ') {
            if (line[i] != name[i]) {
                found = 0;
            }
            i++;
        }
        if (found) {
            i++;
            char num[32];
            int num_size = 0;
            while(line[i] != '\n') {
                if (line[i] == ' ') {
                    num[num_size] = '\0';
                    nums[nums_size] = atoi(num);
                    nums_size++;
                    num_size=0;
                    num[0] = '\0';
                } else {
                    num[num_size] = line[i];
                    num_size++;
                }
                i++;
            }
            fclose(fp);
            return nums_size;
        }
    }
    fclose(fp);
    return 0;
}

void save(char line[], char name[]) {

    if (!strcmp(name, "ALL")) {
        puts("ERROR: 'ALL' is a preserved name");
        exit(1);
    }

    if (set_exists(name)) {
        puts("ERROR: Set with such name already exists in the database");
        exit(1);
    }

    char new_line[1028];
    char num[64];
    int num_counter = 0;

    int set[64];
    int set_size = 0;

    int was_modified = 0;

    for (int i = 0; i <= strlen(line); ++i) {
        if (line[i] == '0' || line[i] == '1') {
            num[num_counter] = line[i];
            num_counter++;
        } else if (line[i] == ' ' || line[i] == '\0') {
            num[num_counter] = '\0';
            int dec = bin_to_dec(num);
            if (!is_member(dec, set, set_size)) {
                set[set_size] = dec;
                set_size++;
                char strdec[64];
                sprintf(strdec, "%d ", bin_to_dec(num));
                strcat(new_line, strdec);
                num_counter = 0;
                num[0] = '\0';
                //strdec[0] = '\0';
            } else {
                was_modified = 1;
            }
        } else {
            num[num_counter] = line[i];
            num_counter++;
            puts("ERROR: Non-binary symbols found in the provided arguments");
            exit(1);
        }
    }

    if (was_modified) {
        puts("Set was modified due to it having dublicated items:");
        printf("%s: { %s};\n", name, new_line);
    }

    FILE *fp;
    fp = fopen("db.txt", "a+");
    
    if (fp == NULL) {
        puts("ERROR: File writing operation failed");
        exit(1);
    }
    
    fprintf(fp, "%s ", name);
    fprintf(fp, "%s\n", new_line);
    
    fclose(fp);
    puts("Set succsessfully written to the database!");
    }

    void show(char name[], char method[]) {
        if (!strcmp(name, "ALL")) {
                FILE *fp;
                fp = fopen("db.txt", "r");
                if (fp == NULL) {
                    puts("ERROR: File writing operation failed");
                    exit(1);
                }
                char *line = NULL;
                size_t len = 0;
                ssize_t read;

                while ((read = getline(&line, &len, fp)) != -1) {
                    int i = 0;
                    char name_temp[32];
                    while(line[i] != ' ') {
                        name_temp[i] = line[i];
                        i++;
                    }
                    name_temp[i] = '\0';
                    show(name_temp, method);
                    name_temp[0] = '\0';
                }
                fclose(fp);
        } else {
            int nums[128] = {};
            int status = read_line(name, nums);

            if (status == 0) {
                puts("ERROR: Set not found in the database");
                exit(1);
            }

            char num_line[1028];

            if (!strcmp(method, "DEC")) {
                for (int i=0; i < status; ++i) {
                    char strdec[32];
                    sprintf(strdec, "%d ", nums[i]);
                    strcat(num_line, strdec);
                    strdec[0] = '\0';
                }
            } else if (!strcmp(method, "BIN")) {
                for (int i=0; i < status; ++i) {
                    char strdec[32];
                    sprintf(strdec, "%d ", dec_to_bin(nums[i]));
                    strcat(num_line, strdec);
                    strdec[0] = '\0';
                }
            } else {
                puts("ERROR: Bad syntax");
                throw_help();
                exit(1);
            }
            printf("%s: { %s};\n", name, num_line);
            num_line[0] = '\0';
        }
    }

    void unite(char name_a[], char name_b[]) {
        int nums_a[128] = {};
        int nums_b[128] = {};
        int status_a = read_line(name_a, nums_a);
        int status_b = read_line(name_b, nums_b);
        if (status_a == 0) {
            printf("ERROR: Set '%s' not found in the database", name_a);
            exit(1);
        }
        if (status_b == 0) {
            printf("ERROR: Set '%s' not found in the database", name_b);
            exit(1);
        }
        int nums_unite[128];
        int size = 0;
        for (int i=0; i < status_a; ++i) {
            if(!is_member(nums_a[i], nums_unite, size)) {
                nums_unite[size] = nums_a[i];
                size++;
            }
        }
        for (int i=0; i < status_b; ++i) {
            if(!is_member(nums_b[i], nums_unite, size)) {
                nums_unite[size] = nums_b[i];
                size++; 
            }
        }
        char num_line[1028];
        for (int i=0; i < size; ++i) {
            char strdec[32];
            sprintf(strdec, "%d ", nums_unite[i]);
            strcat(num_line, strdec);
            strdec[0] = '\0';
        }
        printf("%s and %s union: { %s};\n", name_a, name_b, num_line);
    }

int main(int argc,char* argv[]) {
    if (argc==1) {
        throw_help();
    } else if (!strcmp(argv[1], "HELP") || !strcmp(argv[1], "-h") || !strcmp(argv[1], "-help")) {
            throw_help();
    } else if (argc > 1 && argc < 5) {
        puts("ERROR: No command is corresponding this pattern");
        throw_help();
    } else if (argc == 5) {
        if (!strcmp(argv[1], "SAVE")) {
            if (!strcmp(argv[3], "AS")) {
                save(argv[2], argv[4]);
            } else {
                puts("ERROR: Bad syntax");
                throw_help();
            }
        } else if (!strcmp(argv[1], "SHOW")) {
            if (!strcmp(argv[3], "AS")) {
                show(argv[2], argv[4]);
            } else {
                puts("ERROR: Bad syntax");
                throw_help();
            }
        } else if (!strcmp(argv[1], "UNITE")) {
            if (!strcmp(argv[3], "WITH")) {
                unite(argv[2], argv[4]);
            } else {
                puts("ERROR: Bad syntax");
                throw_help();
            }
        } else {
            puts("ERROR: Unknown command provided");
            throw_help();
        }
    } else {
        puts("ERROR: Too many arguments provided");
        throw_help();
    }
    return 0;
}