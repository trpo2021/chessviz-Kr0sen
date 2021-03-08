#include "move.h"

int check_move_type(
        char boardlocale[BOARDSIZE][BOARDSIZE], char step[STEPMAX], int tib)
{
    int x, y;
    x = BOARDSIZE - step[4 + tib] + ASCII_NUMB_DISLOC;
    y = step[3 + tib] - ASCII_CHAR_START;
    if (!((boardlocale[x][y] == ' ' && step[2 + tib] == '-')
          || (boardlocale[x][y] != ' ' && step[2 + tib] == 'x')))
        return 1;
    return 0;
}

void figure_make_move(
        char boardlocale[BOARDSIZE][BOARDSIZE], char step[STEPMAX], int tib)
{
    int x0, y0, x, y;
    x0 = BOARDSIZE - step[1 + tib] + ASCII_NUMB_DISLOC;
    y0 = step[0 + tib] - ASCII_CHAR_START;
    x = BOARDSIZE - step[4 + tib] + ASCII_NUMB_DISLOC;
    y = step[3 + tib] - ASCII_CHAR_START;
    boardlocale[x][y] = boardlocale[x0][y0];
    boardlocale[x0][y0] = ' ';
}
