#include <stdio.h>
#include <stdlib.h>

const int BOARDSIZE = 8;
const int STEPMAX = 20;
const char ASCII_CHAR_START = 'a';
const char ASCII_CHAR_END = 'k';
const char ASCII_NUMB_START = '1';
const char ASCII_NUMB_END = '8';
const char ASCII_NUMB_DISLOC = '0';
const char ASCII_CHAR_CAPS_DISLOC = 'a' - 'A';

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

int scan_step(char boardlocale[BOARDSIZE][BOARDSIZE])
{
    int i, type_in_beginning;
    char step[STEPMAX];
    for (i = 0; i < STEPMAX; i++)
        step[i] = '0';
    scanf("%s", step);
    //Преждевременное завершение программы.
    if (step[0] == '0')
        return 999;
    //Проверка на наличие типа фигуры в начале строки.
    type_in_beginning = check_beginning(step);
    //Проверка диапазона.
    if (check_range(step, type_in_beginning))
        return 1;
    //Проверка соответствия фигуры.
    if (type_in_beginning && check_figure(boardlocale, step))
        return 2;
    //Проверка типа хода.
    if (check_move_type(boardlocale, step, type_in_beginning))
        return 3;
    //Перемещение фигуры.
    figure_make_move(boardlocale, step, type_in_beginning);
    //Взятие на проходе.
    do_ep(boardlocale, step, type_in_beginning);
    //Превращение.
    transform(boardlocale, step, type_in_beginning);
    //Мат.
    if (step[5 + type_in_beginning] == '#')
        return 999;
    //Рокировка.
    castling(boardlocale, step, type_in_beginning);
    return 0;
}

int main()
{
    int result;
    char board[BOARDSIZE][BOARDSIZE];
    fill_board_std(board);
    while (1) {
        print_board(board);
        result = scan_step(board);
        if (result == 999) { //Завершение.
            print_board(board);
            return 0;
        }
        //Вывод ошибки и возвращение значения.
        if (result == 1) {
            printf("\nВыход за пределы доски.\n");
            return 1;
        }
        if (result == 2) {
            printf("\nФигура не соответствует фактической.\n");
            return 2;
        }
        if (result == 3) {
            printf("\nНеверный тип хода.\n");
            return 3;
        }
    }
}