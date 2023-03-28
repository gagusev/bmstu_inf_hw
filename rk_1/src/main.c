#include "game_logic.h"
 
int main(void) {	
	cur_w *wins = game_init();
    game_loop(wins);
    return 0;
}