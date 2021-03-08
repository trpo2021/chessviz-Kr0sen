#include "fill_board_std.h"

void fill_board_std(char boardlocale[BOARDSIZE][BOARDSIZE])
{
    int i, j;
    boardlocale[0][0] = 'r';
    boardlocale[0][1] = 'n';
    boardlocale[0][2] = 'b';
    boardlocale[0][3] = 'q';
    boardlocale[0][4] = 'k';
    boardlocale[0][5] = 'b';
    boardlocale[0][6] = 'n';
    boardlocale[0][7] = 'r';
    for (i = 0; i < BOARDSIZE; i++) {
        boardlocale[1][i] = 'p';
        boardlocale[BOARDSIZE - 2][i] = 'P';
        for (j = 2; j < BOARDSIZE - 2; j++)
            boardlocale[j][i] = ' ';
    }
    boardlocale[BOARDSIZE - 1][0] = 'R';
    boardlocale[BOARDSIZE - 1][1] = 'N';
    boardlocale[BOARDSIZE - 1][2] = 'B';
    boardlocale[BOARDSIZE - 1][3] = 'Q';
    boardlocale[BOARDSIZE - 1][4] = 'K';
    boardlocale[BOARDSIZE - 1][5] = 'B';
    boardlocale[BOARDSIZE - 1][6] = 'N';
    boardlocale[BOARDSIZE - 1][7] = 'R';
}