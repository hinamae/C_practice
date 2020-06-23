#include	<stdio.h>
#include	<unistd.h> // sleep(),usleep()
#include	"c_game.h"

// ゲーム画面の大きさを定義
#define	XMIN 0
#define	XMAX 79
#define YMIN 0
#define YMAX 24

#define	INC 1     // 増加するときの定義
#define DEC (-1)  // 減算するときの定義

void wait( int cnt )
{
	while( cnt-- )
	 ;
}

int main( void )
{
	int x = 35 , y = 12 ; // ＠の最初の位置を決めている
	int flagx = INC ;    // INC のとき座標xを増加する
	int flagy = INC ;    // INC のとき座標yを増加する
	int chr = 0 ;
	
	KB_init(); //リアルタイムキー入力の初期化
		
	ESC_CursorOff(); // Linuxのカーソル非表示
	ESC_cls(); // 画面消去
	LocateChar( x , y , '@' , C_YELLOW ) ; // 最初の位置に＠を水色で表示する
	
	while( 'q' != chr )
	{
		LocateChar( x , y , ' ' , C_BLACK ) ; // 古い座標の文字をスペースで消す。
		
		if( x <= XMIN )
		{
			x = XMIN ;
			flagx = INC ;
		}
		if( x >= XMAX )
		{
			x = XMAX ;
			flagx = DEC ;
		}
		if( y <= YMIN )
		{
			y = YMIN ;
			flagy = INC ;
		}
		if( y >= YMAX )
		{
			y = YMAX ;
			flagy = DEC ;
		}

		x = x + ( 1 * flagx );
		y = y + ( 1 * flagy );

		LocateChar( x , y , '@' , C_YELLOW ) ; // 改めて書く
		
		if( kbhit() )
			chr = linux_getch();
		usleep( 100 * 1000 ) ; // 単位マイクロ秒
		fflush(stdout); // これを忘れないこと。毎回フラッシュする
	}

	KB_close(); //リアルタイムキー入力の初期化
	ESC_CursorOn(); // Linuxのカーソル表示
	return( TRUE ) ;
}
