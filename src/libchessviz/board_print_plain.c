#include "board_print_plain.h"
#include <stdio.h>

void print_board(char boardlocale[BOARDSIZE][BOARDSIZE])
{
    int i, j;
    printf("\n");
    for (i = 0; i < BOARDSIZE; i++) {
        printf("%d ", BOARDSIZE - i);
        for (j = 0; j < BOARDSIZE; j++) {
            printf("%c ", boardlocale[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}