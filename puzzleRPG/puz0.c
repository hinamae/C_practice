// puzmon0
// インクルード宣言

#include <stdio.h>
#include "puz1.c"


// 列挙型宣言


// グローバル定数の宣言


// // 構造体型宣言
// typedef struct MONSTER{
//     char* name;
// }Monster;

// プロトタイプ宣言
void goDungeon(char* playerName);
void DoBattle(char* monster_pointer);


// 関数宣言

int main(int argc, char** argv){

    printf("***puzzle & monsters***\n");
    char* monster1 = "スライム";
    char* monster2 = "メタルスライム";
    char* monster3 = "ドラキー";
    char* monster4 = "モーモン";
    char* monster5 = "キングメタル";

    char* monster_pointers[5] = {monster1,
                               monster2,
                               monster3,
                               monster4,
                               monster5
                               };
    goDungeon(argv[1]);
    int i;
    for(i=0 ; i<5 ; i++){
    DoBattle(monster_pointers[i]);
    }
    return 0;


}


// ユーティリティ関数宣言