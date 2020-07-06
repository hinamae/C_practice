#include <stdio.h>
// 列挙型宣言
typedef enum Element{FIRE, WALTER, WIND, EARTH, LIFE, EMPTY}Element;


// グローバル定数の宣言
const char ELEMENT_SYMBOLS[EMPTY+1]={'$','~','@','#','&',' '};
const char ESCAPE_SEQ_COLOR[EMPTY+1]={1,6,2,3,5,0};


// 構造体型宣言
// 敵のモンスター
typedef struct MONSTER{
    char* name;
    int HP;
    int maxHP;
    int type;
    int attack;
    int defense;
}Monster;

// 味方のモンスター
typedef struct PARTY{
    char* player;
    Monster* our_players;
    int our_players_num;
    int maxHP;
    int avgHP;
    int avg_defense;
}Party;



typedef struct DUNGEON{
    Monster* monsters;
    int Monsters_num;
} Dungeon;

// プロトタイプ宣言
Party organize(char* player, Monster* ourplayers, int player_num);
void goDungeon(Party myparty);
void DoBattle(Monster dungeon_p);
void printMonsterName(Monster doraque_monster);
void showParty(Party myparty);



void goDungeon(Party myparty){
    showParty(myparty);
}

void DoBattle(Monster dungeon_p){
        printMonsterName(dungeon_p);
        printf( "が現れた\n");
        printMonsterName(dungeon_p);
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

Party organize(char* player, Monster* ourplayers, int player_num){
    int avg_hp=0;
    int max_hp=0;
    int avg_defense=0;
    int i,j;
    for(i=0;i<player_num; i++){
        max_hp += ourplayers[i].maxHP;
    }
    avg_hp=max_hp/player_num;
    for(j=0;j<player_num; j++){
        avg_defense += ourplayers[j].defense;
    }
    avg_defense =avg_defense/player_num;


    // printf("%s",ourplayers->name);
    Party party ={
        player, ourplayers,player_num,max_hp,avg_hp,avg_defense};
    return party;
}

void showParty(Party myparty){
    printf("%sのパーティー(HP=%d)はダンジョンに到着した\n",myparty.player,myparty.maxHP);
    printf("~~~~~~~~~~<Partyの編成>~~~~~~~~~~\n");
    for(int i=0;i<myparty.our_players_num;i++){
        printMonsterName(myparty.our_players[i]);
        printf(" HP= %d",myparty.our_players[i].maxHP);
        printf(" 攻撃= %d",myparty.our_players[i].attack);
        printf(" 防御= %d\n",myparty.our_players[i].defense);
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
}