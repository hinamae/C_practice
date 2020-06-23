// ----------------------------------
// エスケープシーケンスライブラリ関数
// ----------------------------------
// Author : I2K-i2lab@aloha1 05/05/16
// ----------------------------------
#include	<stdio.h>

// Define Value ---------------------
#define DEBUG	0 // 0:nodebug 1:debug
#define	KNOPPIX	1 // 0:DOS	   1:KNOPPIX

#define C_BLACK  30
#define C_BLUE   34
#define C_RED	 31
#define C_MAGENT 35
#define C_GREEN  32
#define C_CYAN   36
#define C_YELLOW 33
#define C_WHITE  37
// ----------------------------------

// ----------------------------------
// Clear Screen Function
// ----------------------------------
// void ESC_cls( void ) ;
// ----------------------------------
void ESC_cls( void )
{
	printf("\033[2J") ;
}

// ----------------------------------
// Cursor Hide Function
// ----------------------------------
// void ESC_CursorOff( void ) ;
// ----------------------------------
void ESC_CursorOff( void )
{
#if KNOPPIX
	printf("\033[?25l") ;
#else
	printf("\033[>5l") ;
#endif
}

// ----------------------------------
// cursor Display Function
// ----------------------------------
// void ESC_CursorOn( void ) ;
// ----------------------------------
void ESC_CursorOn( void )
{
#if KNOPPIX
	printf("\033[?25h") ;
#else
	printf("\033[>5h") ;
#endif
}


// --------------------------------------------
// cursor Display Function
// --------------------------------------------
// void ESC_locte( int x_order , int y_order );
// --------------------------------------------
void ESC_locate( int x , int y )
{
	printf("\033[%d;%dH",y+1 , x+1 );
}


// --------------------------------------------
// Charactor Color setting Function
// --------------------------------------------
// void ESC_setcolor( int color );
// --------------------------------------------
void ESC_setcolor( int color )
{
	printf("\033[%dm",color);
}


// ---------------------------------------------------
// print charctor with color + location Func
// ---------------------------------------------------
// void LocateChar( int x , int y , int ch , int col )
// ---------------------------------------------------
void LocateChar( int x , int y , int ch , int col )
{
	ESC_locate( x , y ); // call locate function
	ESC_setcolor( col ); // set color
	printf("%c",ch);     // print char
}

// ----------------- DEBUG main() --------------------
#if DEBUG
int main( void )
{
	ESC_cls();
	LocateChar( 30 , 10 , '@' , C_BLACK );
	LocateChar( 30 , 11 , '@' , C_BLUE );
	LocateChar( 30 , 12 , '@' , C_RED );
	LocateChar( 30 , 13 , '@' , C_MAGENT );
	LocateChar( 30 , 14 , '@' , C_GREEN );
	LocateChar( 30 , 15 , '@' , C_CYAN );
	LocateChar( 30 , 16 , '@' , C_YELLOW );
	LocateChar( 30 , 17 , '@' , C_WHITE );
	printf("\n");
	return( 0 );
}
#endif
// ---------------------------------------------------
