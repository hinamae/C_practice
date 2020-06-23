// ----------------------------------
// C_GAME Definition Include File  
// ----------------------------------
// Author : I2K-i2lab@aloha1 05/05/16
// ----------------------------------
// Define Value ---------------------
#define C_BLACK  30
#define C_BLUE   34
#define C_RED	 31 
#define C_MAGENT 36 
#define C_GREEN  32 
#define C_CYAN   35
#define C_YELLOW 33
#define C_WHITE  37

#define TRUE 1
#define FALSE 0
// ------------------ Escape Library Function prototype ---
void ESC_cls( void ) ;
void ESC_CursorOff( void ) ;
void ESC_CursorOn( void ) ;
void ESC_locte( int , int );
void ESC_setcolor( int );
void LocateChar( int , int , int , int  );

// ------------------ Real Time key Input -----------------
void KB_init( void ); // キーボードの初期化関数
void KB_close();      // キーボードの終了関数
int kbhit();	      // キーが押されたか？
int linux_getch();    // キーボードから一文字取得


