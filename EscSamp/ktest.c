#include <stdio.h>
#include    "RealKey.h"

int main(void)
{
    puts("何かキーを押したら終了します。");

    while (1) {
        if (kbhit()) {
            printf("'%c'を押しました。\n", Rgetch());
            break;
        }
    }

    return 0;
}

