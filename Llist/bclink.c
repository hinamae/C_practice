/////////リンクリストを実現しているファイル
/////////これらを使用したい場合、llist.hを読み込めばリンクリストをすぐに使えるようになる
#include  <stdio.h>
//これをincludeするをmallocというメモリを確保する関数を使える
#include  <stdlib.h>
#include  "portab.h"
#include  "llist.h"

////////BCLINKの3つのポインタ変数(ポインタ変数は8byteの大きさを持っている)
////////リンクリストを実現させるためのポインタ変数3つ(最初の位置、操作している位置、最後の位置)
GLOBAL BCLINK *First    = BCNULL;  //リンクリストブロックの最初の位置を記録
GLOBAL BCLINK *Current  = BCNULL;  // リストブロックの操作位置の現在位置を記録
GLOBAL BCLINK *Last     = BCNULL;  // 最終ブロック位置を記録している

////////Initialiedにtrueが入っていれば、初期化済み
GLOBAL int Initialized = FALSE; //最初は未初期化状態
////////エラーコード用の変数
GLOBAL int ErrCode = TRUE;  // TRUEのときはエラーが無い

// -----------------------------------------------------------------------------
// FunctionName:		ErrDebug
// CallingSequence: void ErrDebug( code　)
// Parameters:　引数　int code
// リストユーティリティの各部分でエラーが出た時にその内容を明確にコンソールに表示する関数
// -----------------------------------------------------------------------------
void ErrDebug( int errcode )
{ // コードは順次増やす　llist.hの編集も忘れないこと
  switch(errcode)
  {
    case CODE001:printf("%s\n",ERR001);break;
    case CODE002:printf("%s\n",ERR002);break;
  }
}

// -----------------------------------------------------------------------------
// FunctionName:		Lblockmake
// CallingSequence: BCLINK* Lblockmake()
// Parameters:　引数　なし
// リンクリストのメモリブロックを１つ作成し、そのポインタを返す関数
// 最も基本的な関数、メモリの開放はfree()で直に行うほうが良い
// -----------------------------------------------------------------------------
BCLINK* Lblockmake( void )
{
  //エムアロックと読む(stdlib.hをincludeすることによって使えるようになる)
  //Currentはグローバル変数(広域変数)
  //mallocはメモリ不足で確保できない場合、NULLを返す
  Current = malloc( sizeof(BCLINK) );
  if(Current != BCNULL)
    return Current ;
  else
  {
    //NULLの場合
    ErrCode = 001; //001= Lblockmake でエラー　メモリ不足でアロック出来ません
    return( BCNULL );// Error case
  }
}

//たった一回だけ使う関数。初期化
// -----------------------------------------------------------------------------
// FunctionName:		LbInit
// CallingSequence: int LbInit( void )
// Parameters:　引数　なし
// TRUEが返されれば成功
// リンクリストの初期化を行う関数、コールは度だけ。最初の１ブロックを作成する
// 対し、ターミネート関数も用意するが、すべてのメモリを開放する処理はターミネーターとする
// 初期状態を作るのでスタートブロックの１ブロックだけ作成し指標ポインタもセットする
// -----------------------------------------------------------------------------
int LbInit( void )
{
  //すべてのポインタ変数は最初は同じものをさしていなければならない。
  First = Current = Last = Lblockmake();
  if( First != BCNULL )
  {
      Initialized = TRUE; // 初期化済
      return( TRUE );
  }
  else
    return( FALSE );
}

//終了する。メモリを開放。
// -----------------------------------------------------------------------------
// FunctionName:		LbTerminate
// CallingSequence: int LbTerminate( void )
// Parameters:　引数　なし
// TRUEが返されれば成功
// リンクリストを終了しメモリを開放する。Initializedもリセットする。
// -----------------------------------------------------------------------------
int LbTerminate( void )
{
  //BClinkAllFreeが成功しているか確認
  if( BClinkAllFree() == TRUE )
    Initialized = FALSE ; // メモリ解放したので未初期化にリセット
    //関数自体は成功しているのでTRUEを返す
  return( TRUE );
}

//リンクリストのブロックが1こあるとき、リンクリストのブロックを追加する関数。
// -----------------------------------------------------------------------------
// FunctionName:		LBadd
// CallingSequence: int LBadd( void )
// Parameters:　引数　なし
// TRUEが返されれば成功
// 新しくブロックを最後尾に追加する関数
// -----------------------------------------------------------------------------
int LBadd( void )
{
  BCLINK *work ;//作業用ポインタ

  //err check
  if( Last == BCNULL )// 指標が空ポインタの状態かチェックします
  {
    ErrCode = CODE002; return( FALSE );
  }
  work = Lblockmake(); //一個ブロックを作成
  // workがBCNULLだったらエラーにする機能を追加しましょう＝メモリ不足
  if(work == BCNULL) 
  {
    BClinkAllFree();
    Initialized = FALSE; // 未初期化状態に戻す＝リンクもすべてリセットされる。
    return( FALSE);
  }
  // リンクリスト接続処理
  Last->next = work ;
  work->prev = Last ;

  // Lastを更新する
  Last = Current = work ;//Currentも最新のブロックを指し示すので更新
  return( TRUE );
}

//好きな数のリンクブロックをもつリンクリストを作成することができる。引数としてリンクブロック数を指定する。
// -----------------------------------------------------------------------------
// FunctionName:		LBlinkMake
// CallingSequence: int LBlinkMake( int num )
// Parameters:　引数　int num  //リンクリストの数指定
// TRUEが返されれば成功
// 指定した数のリンクリストチェーンを作る。エラーが出たら、すべて開放してFALSEを返す
// -----------------------------------------------------------------------------
int LBlinkMake( int num )
{
  int work = num ;
  //リンクの全くない状態でなければこの関数は使えなくする
  if( Initialized == FALSE ) return( FALSE );

  //workが-1になるまでTRUEであり、くりかえす
  while( work-- )
  {
    if( LBadd() == FALSE && ErrCode == CODE002 ){
      // リンクリストのメモリをすべて開放する関数コール
      return( FALSE );
    }
  }
  return( TRUE );
}

//リンクリストのメモリを全て開放する関数
//stdlib.hをincludeしていれば使用できる。
// -----------------------------------------------------------------------------
// FunctionName:		BClinkAllFree
// CallingSequence: nt BClinkAllFree( void )
// Parameters:　引数　なし
// TRUEが返されれば成功
// Last指標を利用して、現在のリンクリストのメモリを開放する
// -----------------------------------------------------------------------------
int BClinkAllFree( void )
{
  BCLINK *dummy ; //作業用の指標ポインタ
//一番最後のブロックのポインタをdummyに代入
 dummy = Last ;
 //一番最後のブロックのメモリから開放していき、Firstにむかって順次開放していく。
 //Firstのメモリまで開放し終わったら終了にしたいが、このwhile文では、
 //LastとFirstが異なっている場合にメモリを開放するので、First部分のブロックのメモリは開放されずに残っている
 while( Last != First )
 {
   dummy = dummy->prev ;//ひとつ前野ブロックのポインタに入れ替える
   free( Last );        //Lastのメモリを開放
   Last = dummy;        //LastにDummyの値を戻す
 }
 // この時点ではFirstブロックだけ残るので最後にそれを開放する
 free( First );
 //念のために指標をリセット
 First = Current = Last = BCNULL ;
 return( TRUE );
}
