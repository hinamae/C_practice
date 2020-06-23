#include  <stdio.h>
//これをincludeするをmallocというメモリを確保する関数を使える
#include  <stdlib.h>
#include  "portab.h"
#include  "llist.h"


int LBmake(int num){

    int work;
    work = num;
      while( work-- )
      {
        if( work == 5 ){
          printf("%d",work);
        }else if(work == 6){
            printf("workは%dです",work);
        }else{
            printf("workは%dです",work);
        }
      }
      printf("workは%dです",work);
      return( TRUE );
}

int main(void){
    LBmake(8);
}
