//このソースには、ブログでの整形のために全角スペースが入っていますので、
//そのままコピー、コンパイルしてもエラーが出ますのでご注意を。まずは
//全角スペースを半角に置換する必要があります。
// 現在のBerryLinuxでは、Cursesライブラリがインストールされていません。
// 従って自分でアップデートの必要ありです。KNPOOIXは大丈夫です。

/*-----------------------------------------------------*/
/*　kbhit() , linux_getch()　　　　　　　　　　　　　　*/
/*-----------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include <curses.h>
#include <unistd.h>


//---- ターミナル・キー関連の構造体変数
static struct termios Old_set ;
static struct termios New_set ;
static int ReadMoji = -1;

// Definition
#define KEY_DEBUG 0// テストをする場合は１にする
#define TRUE 1
#define FALSE 0

//------------------------------
// ターミナルモードイニシャライズ関数
//------------------------------
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
//-------------------------
// モードを標準に戻す関数
//-------------------------
void KB_close()
{
  tcsetattr(0, TCSANOW, &Old_set); // reset oldinfo
}
//-------------------------
//Dosのkbhit()相当の関数
//-------------------------
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
//-------------------------
// Dosのgeych相当の関数　改
//-------------------------
int Mgetch()
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

// ------------------------
// テストのためのmain()関数
// ------------------------

#if KEY_DEBUG	//この値が１のときはmain()関数が有効
int main()
{
  int ch = 0;

  KB_init(); // イニシャライズ
  printf("\033[2J eキーを押下すると終了します。");

  while(ch != 'e')
  {
 //   sleep(TRUE);
    if(kbhit())
    {
     ch = Mgetch();
     printf("あなたは １６進コード%X : %c キーを押しました\n",ch,ch);
    }
  }
  KB_close();// ターミネート
  exit( FALSE );
}
#endif
