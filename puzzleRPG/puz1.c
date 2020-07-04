#include <stdio.h>
// 列挙型宣言
typedef enum Element{FIRE, WALTER, WIND, EARTH, LIFE, EMPTY}Element;


// グローバル定数の宣言
const char ELEMENT_SYMBOLS[EMPTY+1]={'$','~','@','#','&',' '};
const char ESCAPE_SEQ_COLOR[EMPTY+1]={1,6,2,3,5,0};


// 構造体型宣言
typedef struct MONSTER{
    char* name;
    int HP;
    int maxHP;
    int type;
    int attack;
    int defense;
}Monster;


typedef struct DUNGEON{
    Monster* monsters;
    int Monsters_num;
} Dungeon;

// プロトタイプ宣言
void goDungeon(char* playerName);
void DoBattle(Monster doraque_monster);
void printMonsterName(Monster doraque_monster);



// struct Monster;

void goDungeon(char* playerName){
    printf("%sはダンジョンに到着した!!\n",playerName);
}

void DoBattle(Monster doraque_monster){
    printMonsterName(doraque_monster);
    printf( "が現れた\n");
    printMonsterName(doraque_monster);
    printf( "を倒した！\n");
}

void printMonsterName(Monster doraque_monster){
    printf("%c[4%dm%c%s%c",ESC,
            ESCAPE_SEQ_COLOR[doraque_monster.type],
            ELEMENT_SYMBOLS[doraque_monster.type],
            doraque_monster.name,
            ELEMENT_SYMBOLS[doraque_monster.type]);
    printf("%c[49m",ESC);
}