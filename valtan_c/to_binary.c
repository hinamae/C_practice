#include <stdio.h>
#include <string.h>

int main(void){
    int i,decimal;
    int binary[32];

    // cls();
    // 十進数の入力
    // Locate(0,0);//Ccolor(GREEN);
    printf("10進数=");
    scanf("%d",&decimal);

    for(i=0;decimal>0;i++){
        binary[i]=decimal%2;
        decimal=decimal/2;
    }

    // Locate(0,3);//Ccolor(YELLOW);
    printf("2進数=");
    while(i>0){
        printf("%d",binary[--i]);
    }
    printf("\n");

    return 0;
    
    
    }