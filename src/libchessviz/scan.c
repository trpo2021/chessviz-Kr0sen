#include "scan.h"
#include "checks.h"
#include "constants.h"
#include "move.h"
#include "specialmove.h"
#include <stdio.h>

int scan_step(char boardlocale[BOARDSIZE][BOARDSIZE])
{
    int i, type_in_beginning;
    char step[STEPMAX];
    for (i = 0; i < STEPMAX; i++)
        step[i] = '0';
    scanf("%s", step);
    //Преждевременное завершение программы.
    if (step[0] == '0')
        return EXIT_SUCCESS;
    //Проверка на наличие типа фигуры в начале строки.
    type_in_beginning = check_beginning(step);
    //Проверка диапазона.
    if (check_range(step, type_in_beginning))
        return ERROR_OUT_OF_RANGE;
    //Проверка соответствия фигуры.
    if (type_in_beginning && check_figure(boardlocale, step))
        return ERROR_DIFFERENT_FIGURES;
    //Проверка типа хода.
    if (check_move_type(boardlocale, step, type_in_beginning))
        return ERROR_WRONG_MOVE_TYPE;
    //Перемещение фигуры.
    figure_make_move(boardlocale, step, type_in_beginning);
    //Взятие на проходе.
    do_ep(boardlocale, step, type_in_beginning);
    //Превращение.
    transform(boardlocale, step, type_in_beginning);
    //Мат.
    if (step[5 + type_in_beginning] == '#')
        return EXIT_SUCCESS;
    //Рокировка.
    castling(boardlocale, step, type_in_beginning);
    return CONTINUE_GAME;
}