#include <stdio.h>
// mvaddchなどのために必要
#include <curses.h>
#include "cat.h"
// usleepのために必要
#include <unistd.h>
// コンパイル： gcc  -lncurses practice.c -o  cat
// 実行: ./cat
// pwd      : /Users/hina/Documents/C_practice/valtan_c

int my_mvaddstr(int y, int x, char *str)
{
    for ( ; x < 0; ++x, ++str)
        if (*str == '\0')  return ERR;
    for ( ; *str != '\0'; ++str, ++x)
        if (mvaddch(y, x, *str) == ERR)  return ERR;
    return OK;
}
// プロトタイプ宣言
int my_mvaddstr(int y, int x, char *str);

static char *car[LOGOHEIGHT + 1]
        = {LCAR1, LCAR2, LCAR3, LCAR4, LCAR5, LCAR6, LCAR7, LCAR8, LCAR9, LCAR10, LCAR11, LCAR12,LCAR13,LCAR14,LCAR15, DELLN};

int main(void){

	initscr();
	int x, y, i;
	for (x = COLS - 1; ; --x) {
		y = LINES / 2 - 3;
			for(i=0;i<LOGOHEIGHT;i++){
				// printf("%s","a");	
				my_mvaddstr(y+i, x+17,car[i]);
				// printf("%s",car[i]);	
			}
		// getch();
	    refresh();
	    usleep(20000);
	}
	return(0);
}