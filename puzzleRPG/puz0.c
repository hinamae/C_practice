// gcc puz0.cでコンパイル
// インクルード宣言

#include <stdio.h>
#include "puz.h"
#include "puz1.c"



int main(int argc, char** argv){

    printf("***puzzle & monsters***\n");
    Party myparty;
    Monster our_players[] = {
        {"勇者",100,100,WALTER,10,5},
        {"僧侶",110,150,EARTH,20,15},
        {"魔法使い",120,200,FIRE,30,25},
        {"剣士",130,300,WIND,40,30},
    };
    Monster* our_players_p;

    myparty = organize(argv[1],our_players,4);
    Party* myparty_p;
    myparty_p = &myparty;


    int monster_num=5;
    Monster doraque_Monsters[] = {
        {"スライム",300,300,WALTER,10,5},
        {"メタルスライム",200,200,EARTH,20,15},
        {"ドラキー",300,300,WIND,30,25},
        {"モーモン",400,400,WIND,40,30},
        {"キングメタル",800,800,FIRE,50,40}
    };
    Dungeon dungeon = {doraque_Monsters , 5};
    Dungeon* dungeon_p;
    dungeon_p = &dungeon;
    goDungeon(myparty, dungeon);

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
    
    int i;
    int flg;
    
    // for(i=0 ; i< dungeon.Monsters_num ; i++){
    DoBattle(dungeon_p,myparty_p);
    // }
    return 0;


}


// ユーティリティ関数宣言

