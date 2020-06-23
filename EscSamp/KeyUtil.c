// 現在のBerryLinuxでは、Cursesライブラリがインストールされていません。
// 従って自分でアップデートの必要ありです。KNPOOIXは大丈夫です。

#define WIN     0       //Windowsの場合１にセット
/*-----------------------------------------------------*/
/*　kbhit() , linux_getch()                          */
/*-----------------------------------------------------*/
// ============================================
//  Author(制作者)		T.Watanabe		Date(日付)　2019/02/05
//  Discription(説明) リアルタイムキー　ユーティリティ
// -----------------------------------------------------------------------------
#include <stdio.h>

#if WIN
#include    <conio.h>
#else
#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include <curses.h>
#include <unistd.h>
#endif

//windowsであれば、kbhitとgetchは外部ライブラリとしてもっているため、外にありますよの記述をする
#if WIN
extern int kbhit( void );
extern int getch( void );
#else
//---- ターミナル・キー関連の構造体変数
static struct termios Old_set ;
static struct termios New_set ;
static int ReadMoji = -1;

// Definition
#define KEY_DEBUG 0// テストをする場合は１にする
#define TRUE 1
#define FALSE 0

// -----------------------------------------------------------------------------
// FunctionName:		KB_init
// CallingSequence:　KB_init( void )
// Parameters:　引数　なし
// ターミナルモードイニシャライズ関数
// -----------------------------------------------------------------------------
void KB_init()
{
  tcgetattr(0, &Old_set); // backup old info
  New_set = Old_set; // copy now info
  New_set.c_lflag &= ~ICANON; // new value overwrite
  New_set.c_lflag &= ~ECHO;
  New_set.c_lflag &= ~ISIG;
  New_set.c_cc[VMIN] = 0;
  New_set.c_cc[VTIME] = 0;
  tcsetattr(0, TCSANOW, &Old_set);
}
// -----------------------------------------------------------------------------
// FunctionName:		KB_close
// CallingSequence:　KB_close( void )
// Parameters:　引数　なし
// モードを標準に戻す関数
// -----------------------------------------------------------------------------
void KB_close()
{
  //コピーしてあったターミナルモードを元に戻す
  tcsetattr(0, TCSANOW, &Old_set); // reset oldinfo
}

// -----------------------------------------------------------------------------
// FunctionName:		kbhit
// CallingSequence:　kbhit( void )
// Parameters:　引数　なし
//Dosのkbhit()相当の関数
// -----------------------------------------------------------------------------
int kbhit()
{
  char ch;
  int nread;

  KB_init(); // イニシャライズ

  if(ReadMoji != -1)
  {
    KB_close();
    return TRUE ;
  }
  New_set.c_cc[VMIN]=0;
  tcsetattr(0, TCSANOW, &New_set);
  nread = read(0, &ch, 1);
  New_set.c_cc[VMIN]=1;
  tcsetattr(0, TCSANOW, &New_set);

  if(nread == 1)
  {
    ReadMoji = ch;
    KB_close();
    return TRUE ;
  }
  KB_close();
  return FALSE ;
}

// -----------------------------------------------------------------------------
// FunctionName:		Rgetch
// CallingSequence:　Rgetch( void )
// Parameters:　引数　なし
// Dosのgeych相当の関数　改
// -----------------------------------------------------------------------------
// 何かキーボードが押されたら、read関数でデータストリームから読みこんで、chに格納
int Rgetch()
{
  char ch;
 while(!kbhit())
   ;
    if(ReadMoji != -1)
    {
        ch = ReadMoji;
        ReadMoji = -1;
        return (ch);
    }
    read(0, &ch, 1);
    return (ch);

}

#endif

// ------------------------
// テストのためのmain()関数
// ------------------------
#if KEY_DEBUG	//この値が１のときはmain()関数が有効
#endif
