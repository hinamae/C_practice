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
int onPlayerTurn(Monster* player ,Monster* monster);
int doAttack(Monster* player, Monster* monster);
int onEnemyTurn(Monster* player, Monster* monster);
int doEnemyAttack(Monster* player, Monster* monster);

void goDungeon(Party myparty,Dungeon dungeon);
void DoBattle(Dungeon* dungeon,Party* party);
void printMonsterName(Monster doraque_monster);
void showParty(Party myparty);


void goDungeon(Party myparty,Dungeon dungeon){
    showParty(myparty);
}

// 倒したモンスターの数を返す
void DoBattle(Dungeon* dungeon,Party* party){
        int i=0;
        Monster* monster_p;
        Monster* player_p;
        int flg_win=1 , flg_loose, flg;
        int current_player_id = 0;
        int current_monster_id = 0;

        for(i = 0; i < 100 ; i++){
            if(flg_win == 1){
                printMonsterName(dungeon->monsters[current_monster_id]);
                printf( "が現れた\n");
            }
                // プレイヤーのターン
                player_p = &party->our_players[current_player_id];
                monster_p = &dungeon->monsters[current_monster_id];
                flg_win = onPlayerTurn(player_p,monster_p);
                //プレイヤーが勝利していなければ、モンスターのターン
                if(flg_win != 1){
                    //モンスターのターン(1が戻り値ならプレイヤーの負け)
                    flg_loose = onEnemyTurn(player_p,monster_p);

                //プレイヤーが勝利していれば、
                }else{
                    printMonsterName(dungeon->monsters[current_monster_id]);
                    printf( "を倒した！\n");
                    current_monster_id += 1;
                    if(dungeon->Monsters_num != current_monster_id){                    
                        printf("%sはさらに奥へと進んだ\n",party->player);
                    }
                }
                // プレイヤーがモンスターに敗北していれば、
                if (flg_win != 1 && flg_loose == 1){
                    printf("%sは敗北した!\n",party->our_players[current_player_id].name);
                    current_player_id += 1;
                    //次のプレイヤーを用意する
                    //プレイヤーの数を計算。4人が全員いなくなっていたら、all_loose=1
                }

                if(dungeon->Monsters_num <= current_monster_id){
                    printf("~~~~~~~~~~~~~~~~~~~~\n");
                    printf("ダンジョンを制覇した！\n");
                    printf("~~~~~~~~~~~~~~~~~~~~\n");
                    break;
                }


                if(party->our_players_num <= current_player_id){
                    printf( "GAME OVER\n");
                    break;
                }
            }
            
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

int onPlayerTurn(Monster* player ,Monster* monster){
    printf("【%sのターン】\n",player->name);
    return doAttack(player , monster);
}

//モンスターの現状のHPを返す
int doAttack(Monster* player, Monster* monster){
    printf("ダミー攻撃で80のダメージを与えた\n");
    monster->HP -= 80;
    printf("モンスターのHP:%d\n",monster->HP);

    if( monster->HP <= 0){
        // モンスターのHPが0以下なら1を返す
        return 1;
    }else{
        //それ以外は0を返す
        return 0;
    }
}

int onEnemyTurn(Monster* player, Monster* monster){
    printf("【%sのターン】\n",monster->name);
    return doEnemyAttack(player , monster);

}

int doEnemyAttack(Monster* player, Monster* monster){
    printf("ダミー攻撃で20のダメージを与えた\n");
    player->HP -= 20;
    printf("プレイヤーのHP:%d\n",player->HP);
    if( player->HP <= 0){
        // プレイヤーのHPが0以下なら1を返す
        // プレイヤーの負け
        return 1;
    }else{
        //それ以外は0を返す
        return 0;
    }

}