// gcc puz0.cでコンパイル
// インクルード宣言

#include <stdio.h>
#include <stdlib.h>

#include "puz1.c"



int main(int argc, char** argv){
    printf("\n");
    printf("\n");
    printf("\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("***********                         *********\n");
    printf("***********    puzzle & monsters    *********\n");
    printf("***********                         *********\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    Party myparty;
    Monster our_players[] = {
        {"　勇者　",100,100,WALTER,10,5},
        {"　僧侶　",110,150,EARTH,20,15},
        {"魔法使い",120,200,FIRE,30,25},
        {"　剣士　",130,300,WIND,40,30},
    };
    Monster* our_players_p;

    myparty = organize(argv[1],our_players,4);
    Party* myparty_p;
    myparty_p = &myparty;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");



    int monster_num=5;
    Monster doraque_Monsters[] = {
        {"スライム",300,300,WALTER,10,5},
        {"メタルスライム",200,200,EARTH,20,15},
        {"ドラキー",300,300,WIND,30,25},
        {"モーモン",400,400,WIND,40,30},
        {"キングメタル",800,800,FIRE,50,40}
    };
    //doraque_Monstersは配列の先頭ポインタを渡している
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
    
    int gems[14];
    BattleField battlefield = {myparty_p , doraque_Monsters , gems};
    BattleField* battlefield_p;
    battlefield_p = &battlefield;


    // for(i=0 ; i< dungeon.Monsters_num ; i++){
    DoBattle(dungeon_p,myparty_p,battlefield_p);
    // }



    // int gems[14];
    // BattleField battlefield = {myparty_p,doraque_Monsters_p,gems};
    // BattleField* battlefield_p;
    // fillGems(battlefield_p);

    return 0;


}


// ユーティリティ関数宣言

