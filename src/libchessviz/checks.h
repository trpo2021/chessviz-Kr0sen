#pragma once
#include "constants.h"

int check_beginning(char step[STEPMAX]);
int check_range(char step[STEPMAX], int tib); // tib = Figure type in beginning
int check_figure(char boardlocale[BOARDSIZE][BOARDSIZE], char step[STEPMAX]);