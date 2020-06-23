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

//---- プロトタイプ
void KB_init();
void KB_close();
int kbhit();
int linux_getch();

//---- ターミナル・キー関連の構造体変数
static struct termios Old_set ;
static struct termios New_set ;
static int ReadMoji = -1;

// Definition
#define KEY_DEBUG 0 // 1 でmain()を付けてデバッグできる
#define TRUE 1
#define FALSE 0

void KB_init()
{
  //tcgetattr関数=端末の状態をtermios構造体のOld_setアドレスに保持しておく
  tcgetattr(0, &Old_set); // backup old info
  New_set = Old_set; // copy now info
  New_set.c_lflag &= ~ICANON; // new value overwrite
  New_set.c_lflag &= ~ECHO;
  New_set.c_lflag &= ~ISIG;
  New_set.c_cc[VMIN] = 0;
  New_set.c_cc[VTIME] = 0;
  tcsetattr(0, TCSANOW, &Old_set);
}

void KB_close()
{
  tcsetattr(0, TCSANOW, &Old_set); // reset oldinfo
}

int kbhit()
{
  char ch;
  int nread;

  if(ReadMoji != -1)
    return TRUE ;

  New_set.c_cc[VMIN]=0;
  tcsetattr(0, TCSANOW, &New_set);
  nread = read(0, &ch, 1);
  New_set.c_cc[VMIN]=1;
  tcsetattr(0, TCSANOW, &New_set);

  if(nread == 1)
  {
    ReadMoji = ch;
    return TRUE ;
  }
  return FALSE ;
}

int linux_getch()
{
  char ch;

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

#if KEY_DEBUG
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
     ch = linux_getch();
     printf("あなたは １６進コード%X : %c キーを押しました\n",ch,ch);
    }
  }
  KB_close();// ターミネート
  exit( FALSE );
}
#endif 
