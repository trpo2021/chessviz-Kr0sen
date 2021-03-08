#include "specialmove.h"
#include <stdlib.h>

void do_ep(char boardlocale[BOARDSIZE][BOARDSIZE], char step[STEPMAX], int tib)
{
    int x, y;
    x = BOARDSIZE - step[4 + tib] + ASCII_NUMB_DISLOC;
    y = step[3 + tib] - ASCII_CHAR_START;
    if (step[5 + tib] == 'e' && step[6 + tib] == '.' && step[7 + tib] == 'p'
        && step[8 + tib] == '.') {
        if (boardlocale[x][y] == 'p' && boardlocale[x - 1][y] == 'P')
            boardlocale[x - 1][y] = ' ';
        else if (boardlocale[x][y] == 'P' && boardlocale[x + 1][y] == 'p')
            boardlocale[x + 1][y] = ' ';
    }
}

void transform(
        char boardlocale[BOARDSIZE][BOARDSIZE], char step[STEPMAX], int tib)
{
    int x, y;
    x = BOARDSIZE - step[4 + tib] + ASCII_NUMB_DISLOC;
    y = step[3 + tib] - ASCII_CHAR_START;
    if (step[5 + tib] == 'K' || step[5 + tib] == 'Q' || step[5 + tib] == 'R'
        || step[5 + tib] == 'B' || step[5 + tib] == 'N') {
        if (boardlocale[x][y] == 'P')
            boardlocale[x][y] = step[5 + tib];
        else
            boardlocale[x][y] = step[5 + tib] + ASCII_CHAR_CAPS_DISLOC;
    }
}

void castling(
        char boardlocale[BOARDSIZE][BOARDSIZE], char step[STEPMAX], int tib)
{
    int i;
    int x, y, sign;
    x = BOARDSIZE - step[4 + tib] + ASCII_NUMB_DISLOC;
    y = step[3 + tib] - ASCII_CHAR_START;
    sign = (step[0 + tib] - step[3 + tib]) / abs(step[0 + tib] - step[3 + tib]);
    if (step[5 + tib] == '0' && step[6 + tib] == '-' && step[7 + tib] == '0'
        && step[8 + tib] == '-' && step[9 + tib] == '0') {
        for (i = y; (i < BOARDSIZE) && (i >= 0); i -= sign) {
            if ((boardlocale[x][i] == 'R' && boardlocale[x][y] == 'K')
                || (boardlocale[x][i] == 'r' && boardlocale[x][y] == 'k')) {
                boardlocale[x][y + sign] = boardlocale[x][i];
                boardlocale[x][i] = ' ';
                break;
            }
        }
    } else if (
            step[5 + tib] == '0' && step[6 + tib] == '-'
            && step[7 + tib] == '0') {
        boardlocale[x][y + sign] = boardlocale[x][y - sign];
        boardlocale[x][y - sign] = ' ';
    }
}