#include  <stdio.h>
#include  "portab.h"
#include  "llist.h"
#include  "esc.h"


int main()
{
  cls();
  // エラー表示テスト
  Locate(0,10);
  // ErrDebug( CODE001 );
  Locate(0,15);
  LbInit();
  LBlinkMake( 1000 );
 printf( "First = %p\n",First);
 printf( "Current = %p\n",Current);
 printf( "Last = %p\n",Last);
 LbTerminate();
  return(0);
}
