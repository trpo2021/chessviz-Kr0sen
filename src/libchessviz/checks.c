#include "checks.h"

int check_beginning(char step[STEPMAX])
{
    if (step[0] == 'K' || step[0] == 'Q' || step[0] == 'R' || step[0] == 'B'
        || step[0] == 'N' || step[0] == 'P')
        return 1;
    return 0;
}

int check_range(char step[STEPMAX], int tib) // tib = Figure type in beginning
{
    if (!((step[0 + tib] >= ASCII_CHAR_START && step[0 + tib] <= ASCII_CHAR_END)
          && (step[1 + tib] >= ASCII_NUMB_START
              && step[1 + tib] <= ASCII_NUMB_END)))
        return 1;
    if (!((step[3 + tib] >= ASCII_CHAR_START && step[3 + tib] <= ASCII_CHAR_END)
          && (step[4 + tib] >= ASCII_NUMB_START
              && step[4 + tib] <= ASCII_NUMB_END)))
        return 1;
    return 0;
}

int check_figure(char boardlocale[BOARDSIZE][BOARDSIZE], char step[STEPMAX])
{
    int x, y;
    x = BOARDSIZE - step[2] + ASCII_NUMB_DISLOC;
    y = step[1] - ASCII_CHAR_START;
    if (!((step[0] == boardlocale[x][y])
          || (step[0] == boardlocale[x][y] - ASCII_CHAR_CAPS_DISLOC))) {
        return 1;
    }
    return 0;
}