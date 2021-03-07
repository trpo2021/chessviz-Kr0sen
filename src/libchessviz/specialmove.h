#pragma once

void do_ep(char boardlocale[BOARDSIZE][BOARDSIZE], char step[STEPMAX], int tib);
void transform(
        char boardlocale[BOARDSIZE][BOARDSIZE], char step[STEPMAX], int tib);
void castling(
        char boardlocale[BOARDSIZE][BOARDSIZE], char step[STEPMAX], int tib);