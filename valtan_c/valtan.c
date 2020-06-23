#include <stdio.h>
#include	<stdio.h>
#include	<unistd.h> // sleep(),usleep()
#include	"c_game.h"

//ターミナルの制御コード。エスケープシーエンスの開始
// #define ESC \033
#define WAIT (10000000/2)
#define LOOP 200

int main(void){
    int xpos =8;
    int ypos = 8;
    int i = 0;
    long j;
	printf("\033[2J") ;


    for(i=0; i<200; i+=2){
        //端まで行ったら一段下がる
        xpos = i%80+1;
        if (xpos==1) ypos++;

        // 腕を上げる
        printf("\033[%d;%dH  Yo¥¥oY" , ypos ,xpos);
        printf("\033[%d;%dH    w   " , ypos+1 ,xpos);
        printf("\033[%d;%dH   | |   " , ypos+2 ,xpos);

        for (j=0; j<WAIT ; j++){ }

         // 腕を下げる
        printf("\033[%d;%dH   o¥¥o " , ypos ,xpos+1);
        printf("\033[%d;%dH >- w -<" , ypos+1 ,xpos+1);
        printf("\033[%d;%dH   < >  " , ypos+2 ,xpos+1);
        for (j=0; j<WAIT ; j++){ }

        }
    printf("/nPress [Enter]");
    (void)getchar();//エンターキーを押せば終了

    // printf("%c[>51" );//カーソルを表示
    // printf("%c[39m" );//文字色を戻す



    }


