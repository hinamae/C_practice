/////////////// リンクリスト用の各種定義をおこなうヘッダファイル。bclink.cで読みこまれる
// リンクリストの構造体型のゼロ
//BCNULLというのはリンクリストの構造体型の変数の中身が0かどうか
//リンクリストのブロックとして、BCLINK型のNULLだったらなにもリンクリストが存在していない状態だとみなす
#define BCNULL (struct BClink *)NULL

//BCLINK型を定義している　リンクリストを実現するための構造体の定義
typedef struct BClink{
  ///////ひとつのBCLINK構造体は、8+8+512+4(LONG)+4+4=540byteの大きさ
  ///////540byteのブロックがリンクされていく。
  //BCLINK型の定義が完全に終わっていないうちなため、BClink型を使用。そうするとエラーが出ない。// https://www.sejuku.net/blog/24473
  // BCNULLを先に定義したいがために型のつけかえ(BClinkからBCLINK)の方法で宣言をしてるのか？
  struct BClink *prev ;
  struct BClink *next ;
  char  hashcode[512]; // ハッシュ化した自身のアドレスを暗号第一keyとして格納予定。第二Keyは別管理
  //地震のポインタ
  long  myip;
  //次のポインタ
  long  nextip;
  //前のポインタ
  long  previp;
  /* Block DATA */
  // ブロックデーターを取り出すにはハッシュコードを要求される仕組みにする。
} BCLINK;

// エラーコード定義
//例外が出てきた場合にエラーコードを定義する。コード001が返された場合、Lblockmake でエラーという日本語文字列を表示するという関数を定義するために、先に変数として定義する
#define CODE001 001
#define ERR001  "Lblockmake でエラー　メモリ不足でアロック出来ません"
//例外が出てきた場合にエラーコードを定義する。コード002が返された場合、指標が空ポインタなので追加できませんという日本語文字列を表示するという関数を定義するために、先に変数として定義する
#define CODE002 002
#define ERR002  "指標が空ポインタなので追加できません。初期化が必要です"

// プロトタイプ宣言
// 外部のファイルから変数を使うことを宣言しておく
extern BCLINK *First ;    //リンクリストブロックの最初の位置を記録
extern BCLINK *Current ;  // リストブロックの操作位置の現在位置を記録
extern BCLINK *Last ;     // 最終ブロック位置を記録している
extern int Initialized;   // 初期化済の場合は、TRUE
extern int ErrCode ;      // TRUEのときはエラーが無い

//  関数のプロトタイプ宣言
extern void ErrDebug( int );
extern BCLINK* Lblockmake( void );
extern int LbInit( void );
extern int LbTerminate( void );
extern int LBadd( void );
extern int LBlinkMake( int );
extern int BClinkAllFree( void );
