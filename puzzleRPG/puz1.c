#include <stdio.h>
// 構造体型宣言
typedef struct MONSTER{
    char* name;
    int HP;
    int maxHP;
    int type;
    int attack;
    int defense;
}Monster;

// struct Monster;

void goDungeon(char* playerName){
    printf("%sはダンジョンに到着した!!\n",playerName);
}

void DoBattle(Monster doraque_monster){
    printf( "%sが現れた\n",doraque_monster.name);
    printf( "%sを倒した！\n",doraque_monster.name);

}

// void printMonsterName(){

// }