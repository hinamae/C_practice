// puzmon0
// インクルード宣言

#include <stdio.h>
#include "puz.h"
#include "puz1.c"



int main(int argc, char** argv){

    printf("***puzzle & monsters***\n");

    int monster_num=5;
    Monster doraque_Monsters[] = {
        {"スライム",100,100,WALTER,10,5},
        {"メタルスライム",200,200,EARTH,20,15},
        {"ドラキー",300,300,WIND,30,25},
        {"モーモン",400,400,WIND,40,30},
        {"キングメタル",800,800,FIRE,50,40}
    };
    Dungeon dungeon = {doraque_Monsters , 5};
    Dungeon* dungeon_p;

    // char* monster1 = "スライム";
    // char* monster2 = "メタルスライム";
    // char* monster3 = "ドラキー";
    // char* monster4 = "モーモン";
    // char* monster5 = "キングメタル";

    // char* monster_pointers[5] = {monster1,
    //                            monster2,
    //                            monster3,
    //                            monster4,
    //                            monster5
    //                            };
    goDungeon(argv[1]);
    int i;
    for(i=0 ; i< dungeon_p->Monsters_num ; i++){
        DoBattle(doraque_Monsters[i]);
    }
    return 0;


}


// ユーティリティ関数宣言

