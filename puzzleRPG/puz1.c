#include <stdio.h>
#include <stdlib.h>
#include "puz.h"
///////////// 列挙型宣言
typedef enum Element{FIRE, WALTER, WIND, EARTH, LIFE, EMPTY}Element;
typedef enum MAX_GEMS{A,B,C,D,E,F,G,H,I,J,K,L,M,N}MAX_GEMS;

//////////// グローバル定数の宣言
const char ELEMENT_SYMBOLS[EMPTY+1]={'$','~','@','#','&',' '};
const char ESCAPE_SEQ_COLOR[EMPTY+1]={1,6,2,3,5,0};

////////////構造体型宣言
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
    int HP;
    int avgHP;
    int avg_defense;
}Party;


//ダンジョン
typedef struct DUNGEON{
    Monster* monsters;
    int Monsters_num;
} Dungeon;

//バトル画面
typedef struct BATTLEFIELD{
    Party* party;
    Monster* monster;
    int* gems;
}BattleField;




/////////////// プロトタイプ宣言
Party organize(char* player, Monster* ourplayers, int player_num);
int onPlayerTurn(BattleField* battlefield, int current_monster_id);
int doAttack(BattleField* battlefield, int current_monster_id);
int onEnemyTurn(BattleField* battlefield, int current_monster_id);
int doEnemyAttack(BattleField* battlefield, int current_monster_id);

void goDungeon(Party myparty,Dungeon dungeon);
void DoBattle(Dungeon* dungeon,Party* party,BattleField* battlefield);
void printMonsterName(Monster doraque_monster);
void showParty(Party myparty);
void fillGems(BattleField* battlefield);
void showBattleField(BattleField* battlefield, int current_monster_id);
void printGems(int* gem);
void printGem(int id);


void goDungeon(Party myparty,Dungeon dungeon){
    showParty(myparty);
}

// 倒したモンスターの数を返す
void DoBattle(Dungeon* dungeon,Party* party,BattleField* battlefield){
        int i=0;
        int flg_win=1 , flg_loose, flg;
        int current_player_id = 0;
        int current_monster_id = 0;

        for(i = 0; i < 100 ; i++){
            // モンスターに勝った場合次のモンスターが出てくる
            if(flg_win == 1){
                printf("\n");
                printMonsterName(dungeon->monsters[current_monster_id]);
                printf( "(HP=%d)が現れた\n",dungeon->monsters[current_monster_id].maxHP);
                printf( "\n");
                printf("               ");
                printf( "\n");
                printf( "\n");
            }
                // プレイヤーのターン
                flg_win = onPlayerTurn(battlefield,current_monster_id);
                //プレイヤーが勝利していなければ、モンスターのターン
                if(flg_win != 1){
                    //モンスターのターン(1が戻り値ならプレイヤーの負け)
                    flg_loose = onEnemyTurn(battlefield,current_monster_id);

                //プレイヤーが勝利していれば、
                }else{
                    printMonsterName(battlefield->monster[current_monster_id]);
                    printf( "を倒した！\n");
                    current_monster_id += 1;
                    if(dungeon->Monsters_num != current_monster_id){                    
                        printf("%sはさらに奥へと進んだ\n",party->player);
                    }
                }
                // プレイヤーがモンスターに敗北していれば、
                if (flg_win != 1 && flg_loose == 1){
                    printf("%sは敗北した!\n",party->player);
                    printf( "GAME OVER\n");
                    break;
                    //次のプレイヤーを用意する
                }

                if(dungeon->Monsters_num <= current_monster_id){
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("                 %sはダンジョンを制覇した!!           \n",party->player);
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

                    break;
                }

            }
            
}

//プレイヤーのターンのバトルフィールドを表示する
//doAttackの結果が帰る
int onPlayerTurn(BattleField* battlefield, int current_monster_id){
    int return_code;
    // printf("【%sのターン】\n", battlefield->party->player);
    return_code = doAttack(battlefield,current_monster_id);
    showBattleField(battlefield,current_monster_id);
    
    return return_code;
}

//モンスターに80ダメージ与える
//モンスターのダメージ後のHPを表示
int doAttack(BattleField* battlefield, int current_monster_id){
    // printf("ダミー攻撃で80のダメージを与えた\n");
    battlefield->monster[current_monster_id].HP -= 80;
    // printf("モンスターのHP:%d\n",battlefield->monster[current_monster_id].HP);

    if( battlefield->monster[current_monster_id].HP <= 0){
        // モンスターのHPが0以下なら1を返す
        return 1;
    }else{
        //それ以外は0を返す
        return 0;
    }
}

int onEnemyTurn(BattleField* battlefield, int current_monster_id){
    int return_code;
    printf("【%sのターン】\n",battlefield->monster[current_monster_id].name);
    return_code =  doEnemyAttack(battlefield, current_monster_id);
    return return_code;
}

int doEnemyAttack(BattleField* battlefield, int current_monster_id ){
    printf("ダミー攻撃で20のダメージを与えた\n");
    battlefield->party->HP -= 20;
    // printf("プレイヤーのHP:%d\n",battlefield->party->HP);
    if( battlefield->party->HP <= 0){
        // プレイヤーのHPが0以下なら1を返す
        // プレイヤーの負け
        return 1;
    }else{
        //それ以外は0を返す
        return 0;
    }

}

//プレイヤーのターンのバトルフィールド
void showBattleField(BattleField* battlefield,int current_monster_id){
    //実行時、第一引数に指定した名前を表示する
    printf("      \n");
    printf("【%sのターン】\n",battlefield->party->player);
    printf("----------------------------------------------------\n");
    printf("                                    \n");
    printf("                                    \n");
    printf("               ");
    printMonsterName(battlefield->monster[current_monster_id]);
    printf("\n");
    printf("               ");
    printf( "HP= %d / %d",battlefield->monster[current_monster_id].HP,
    battlefield->monster[current_monster_id].maxHP);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("  ");

    for(int i=0;i < battlefield->party->our_players_num ; i++){
    printMonsterName(battlefield->party->our_players[i]);
    printf("  ");
    
    }
    printf("\n");
    printf("               ");
    printf( "HP= %d / %d",battlefield->party->HP,battlefield->party->maxHP);
    
    printf("\n");
    printf("\n");

    




    printf("         ");
    
    fillGems(battlefield);

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");


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
        player, ourplayers,player_num,max_hp,max_hp,avg_hp,avg_defense};
    return party;
}

void showParty(Party myparty){
    printf("%sのパーティー(HP=%d)はダンジョンに到着した\n",myparty.player,myparty.maxHP);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~<Partyの編成>~~~~~~~~~~~~~~~~~\n");
    printf("\n");
    for(int i=0;i<myparty.our_players_num;i++){
        printMonsterName(myparty.our_players[i]);
        printf(" HP= %d",myparty.our_players[i].maxHP);
        printf(" 攻撃= %d",myparty.our_players[i].attack);
        printf(" 防御= %d\n",myparty.our_players[i].defense);
    }
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    
}



void fillGems(BattleField* battlefield){
    
    for(int i =0 ; i < N+1;i++){
        // 0~5までの乱数を発生させる
        battlefield->gems[i] = rand()% (EMPTY + 1);
        // printf("%d ",battlefield->gems[i]);
    }

    //printGemsを呼び出す
    printGems(battlefield->gems);
}


// 複数のGemを表示
void printGems(int* gem){
    for(int i =0; i<N+1; i++){
        printGem(gem[i]);
        printf(" ");
        if(i==N){
            printf("\n");
        }
    }
}

// 1つのGemを表示
void printGem(int id){

        printf("%c[4%dm%c",ESC,
            ESCAPE_SEQ_COLOR[id],
            ELEMENT_SYMBOLS[id]);
        printf("%c[49m",ESC);
        
}




// int main(void){
//     int a[14];
//     for(int i =0 ; i < N+1;i++){
//         // 0~5までの乱数を発生させる
        
//         a[i] = rand()% (EMPTY +1);
//         printf("%d\n",a[i]);
//     }
//     for(int i=0; i < N+1; i++){
//         printf("%c[4%dm%c",ESC,
//             ESCAPE_SEQ_COLOR[a[i]],
//             ELEMENT_SYMBOLS[a[i]]);
//         printf("%c[49m",ESC);
//         printf(" ");
//         if(i==N){
//             printf("\n");
//         }
//     }
// }