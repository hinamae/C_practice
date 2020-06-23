#include	<stdio.h>
#include  <stdlib.h>
#include	"portab.h"		//　汎用定義用のインクルードファイル
#include	"RealKey.h"
#include	"esc.h"
// ============================================
//  Author(制作者)						Date(日付)
//  Discription(説明)
// -----------------------------------------------------------------------------
// FunctionName(関数名):
// CallingSequence(使い方):
// Parameters(引数の仕様):
// -----------------------------------------------------------------------------
// ============================================
//  Author(制作者)		T.Watanabe		Date(日付)　2019/02/05
//  Discription(説明) エスケープシーケンス　ユーティリティ
// -----------------------------------------------------------------------------
#define		DEBUG 1		// 0 の時は、メイン関数は有効ではない
// ============================================

// -----------------------------------------------------------------------------
// FunctionName:		CursorUp
// CallingSequence:　CursorUp()
// Parameters:　引数　なし
// カーソルを上方向に移動
// -----------------------------------------------------------------------------
void	CursorUp( void )
{
	printf("\033[1A") ;
}
//カーソルをｎだけ上へ
void	CursornUp( int num )
{
	printf("\033[%dA",num) ;
}

// -----------------------------------------------------------------------------
// FunctionName:		CursorDown
// CallingSequence:　CursorDown()
// Parameters:　引数　なし
// カーソルを ↓方向に移動
// -----------------------------------------------------------------------------
void	CursorDown( void )
{
	printf("\033[1B") ;
}
//カーソルをｎだけ下へ
void	CursornDown( int num )
{
	printf("\033[%dB",num) ;
}
// -----------------------------------------------------------------------------
// FunctionName:		CursorRight
// CallingSequence:　CursorRight()
// Parameters:　引数　なし
// カーソルを右方向に移動
// -----------------------------------------------------------------------------
void	CursorRight( void )
{
	printf("\033[1C") ;
}
//カーソルをｎだけ右へ
void	CursornRight( int num )
{
	printf("\033[%dC",num) ;
}
// -----------------------------------------------------------------------------
// FunctionName:		CursorLeft
// CallingSequence:　CursorLeft()
// Parameters:　引数　なし
// カーソルを左方向に移動
// -----------------------------------------------------------------------------
void	CursorLeft( void )
{
	printf("\033[1D") ;
}
//カーソルをｎだけ左へ
void	CursornLeft( int num )
{
	printf("\033[%dD",num) ;
}
// -----------------------------------------------------------------------------
// FunctionName(関数名):　Locate
// CallingSequence(使い方):Locate(x,y)
// Parameters(引数の仕様):int x =桁数　、int y =行数
// カーソルを　ｘ桁　y行に移動する
// -----------------------------------------------------------------------------
// コンソール平面を　８０桁２５行　　（０−＞２４）（０−＞７９）　とすると
// コンソール（ターミナル）の大きさに合わせて変更できます。
#define XMIN 0
#define XMAX 79
#define YMIN 0
#define YMAX 24
void Locate( int x , int y)
{
	// 必ずカーソルをコンソール平面内に収める
	if(x <= XMIN) x=1;
	if(y <= YMIN) y=1;
	if(x >= XMAX) x=79;
	if(y >= YMAX) y=24;

	printf("\033[%d;%dH",y,x );
}

// -----------------------------------------------------------------------------
// FunctionName:		ConSCrollDwn
// CallingSequence:ConSCrollDwn( n )
// Parameters:　引数　int n
// n行分コンソールを次にスクロール
// -----------------------------------------------------------------------------
void ConScrollDwn( int n )
{
	printf("\033[%dS",n);
}

// -----------------------------------------------------------------------------
// FunctionName:		ConSCrollUp
// CallingSequence:ConSCrollUp( n )
// Parameters:　引数　int n
// n行分コンソールを前にスクロール
// -----------------------------------------------------------------------------
void ConScrollUp( int n )
{
	printf("\033[%dT",n);
}


// -----------------------------------------------------------------------------
// FunctionName:		Cattr
// CallingSequence:　Cattr( mode )
// Parameters:　引数　int mode＝アトリビュートはesc.h参照のこと
// 文字のアトリビュートを変更する
// -----------------------------------------------------------------------------
void Cattr( int mode )
{
	printf("\033[%dm", mode );
}

// -----------------------------------------------------------------------------
// FunctionName:		Ccolor
// CallingSequence:　Cattr( color )
// Parameters:　引数　int color　＝カラーコードesc.h参照のこと
// 文字の色を変更する
// -----------------------------------------------------------------------------
void Ccolor( int color )
{
	printf("\033[%dm", color );
}

// -----------------------------------------------------------------------------
// FunctionName:		cls
// CallingSequence:　cls()
// Parameters:　引数　なし
// コンソール画面を消去する
// -----------------------------------------------------------------------------
void cls( void)
{
	printf("\033[2J");
}
