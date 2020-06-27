#include <stdio.h>
#include <stdio.h>
#include <unistd.h> // sleep(),usleep()

//  gcc  valtan.c -o  val
//ターミナルの制御コード。エスケープシーエンスの開始
#define ESC "\033"
#define WAIT (10000000/2)
#define LOOP 200

int main(void){
    int xpos =1;
    int ypos = 1;
    int i = 0;
    long j;
	printf("%s[2J",ESC) ;


    for(i=0; i<2000; i+=2){
        //端まで行ったら一段下がる
        xpos = i%80+1;
        if (xpos==1) ypos++;

        // 腕を上げる
        printf("%s[%d;%dH  Yo¥¥oY" ,ESC, ypos ,xpos);
        printf("%s[%d;%dH    w   " ,ESC, ypos+1 ,xpos);
        printf("%s[%d;%dH   | |   " ,ESC, ypos+2 ,xpos);
        fflush(stdout);//バッファをフラッシュ
        for (j=0; j<WAIT ; j++){ }

         // 腕を下げる
        printf("%s[%d;%dH   o¥¥o " ,ESC, ypos ,xpos+1);
        printf("%s[%d;%dH >- w -<" ,ESC, ypos+1 ,xpos+1);
        printf("%s[%d;%dH   < >  " ,ESC, ypos+2 ,xpos+1);
        fflush(stdout);//バッファをフラッシュ
        for (j=0; j<WAIT ; j++){ }
        }
    printf("\nPress [Enter]");
    (void)getchar();//エンターキーを押せば終了

    // printf("%s[>51" );//カーソルを表示
    // printf("%s[39m" );//文字色を戻す



    }


