#pragma once
#include "constants.h"

int check_move_type(
        char boardlocale[BOARDSIZE][BOARDSIZE], char step[STEPMAX], int tib);
void figure_make_move(
        char boardlocale[BOARDSIZE][BOARDSIZE], char step[STEPMAX], int tib);