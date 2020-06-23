// 文字のカラーとアトリビュート
// 対応していないコンソール画面もあるので実際に試験すること
#define	RESET		0	//アトリビュートをリセットする
#define	STRONG	1	//強調文字にする
#define	WEAK		2	//薄くする
#define	ITALIC	3	//イタリックにする
#define	UNDERL	4	//アンダーライン
#define	BLINK		5	//ブリンクする
#define	BLINKF	6	//高速ブリンクする
#define	TURNOV	7	//文字の反転
#define	HIDE		8	//文字を隠す
#define	CANCEL	9	//文字のキャンセル

//--------------------------
// 文字のカラーコード
//--------------------------
#define	BLACK		30	// Black
#define	RED		31	// Red
#define	GREEN		32	// Green
#define	YELLOW		33	// Yellow
#define	BLUE		34	// Blue
#define	MAGENTA 	35	// Magenta
#define	CYAN		36	// Cyan
#define	WHITE		37	// White
#define  CRESET	39		// Reset

// 文字の背景色指定
#define	B_BLACK		40	// BBlack
#define	B_RED		41	// BRed
#define	B_GREEN		42	// BGreen
#define	B_YELLOW	43	// BYellow
#define	B_BLUE		44	// BBlue
#define	B_MAGENTA 	45	// BMagenta
#define	B_CYAN		46	// BCyan
#define	B_WHITE		47	// BWhite
#define B_CRESET	49	// BRest

// エスケープシーケンス関連の関数のプロトタイプやその他定義など

void	CursorUp( void );
void	CursornUp( int );
void	CursorDown( void );
void	CursornDown( int );
void	CursorRight( void );
void	CursornRight( int );
void	CursorLeft( void );
void	CursornLeft( int );
void Locate( int , int);
void ConScrollDwn( int );
void ConScrollUp( int );
void Cattr( int );
void Ccolor( int );
void cls( void );
