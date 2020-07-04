#include <stdio.h>

void goDungeon(char* playerName){
    printf("%sはダンジョンに到着した!!\n",playerName);
}

void DoBattle(char* monster_pointers){
    printf( "%sが現れた\n",monster_pointers);
    printf( "%sを倒した！\n",monster_pointers);

}