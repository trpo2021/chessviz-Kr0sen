#include <stdio.h>
#include <stdlib.h>

int move = 0;

char board[8][8]
        = {"rnbqkbnr",
           "pppppppp",
           "        ",
           "        ",
           "        ",
           "        ",
           "PPPPPPPP",
           "RNBQKBNR"};

char step[20] = "00000000000000000000";

void printBoard()
{
    int i, j;
    printf("\n");
    for (i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for (j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

int scanStep()
{
    int i;
    scanf("%s", step);
    //Преждевременное завершение программы.
    if (step[0] == '0')
        return 0;
    //Проверка диапазона.
    if (!(((step[0] >= 97 && step[0] <= 104)
           && (step[1] >= 49 && step[1] <= 56))
          || ((step[1] >= 97 && step[1] <= 104)
              && (step[2] >= 49 && step[2] <= 56)))) {
        return 1;
    }
    //Проверка на наличие типа фигуры в начале строки.
    if (step[0] == 'K' || step[0] == 'Q' || step[0] == 'R' || step[0] == 'B'
        || step[0] == 'N' || step[0] == 'P') {
        //Проверка соответствия фигуры.
        if (!(step[0] == board[8 - step[2] + 48][step[1] - 97]
              || step[0] == board[8 - step[2] + 48][step[1] - 97] - 32)) {
            return 2;
        }
        //Проверка типа хода.
        if (!((board[8 - step[5] + 48][step[4] - 97] == ' ' && step[3] == '-')
              || (board[8 - step[5] + 48][step[4] - 97] != ' '
                  && step[3] == 'x'))) {
            return 3;
        }
        //Проверка диапазона.
        if ((step[4] >= 97 && step[4] <= 104)
            && (step[5] >= 49 && step[5] <= 56)) {
            //Перемещение фигуры.
            board[8 - step[5] + 48][step[4] - 97]
                    = board[8 - step[2] + 48][step[1] - 97];
            board[8 - step[2] + 48][step[1] - 97] = ' ';
            //Взятие на проходе.
            if ((step[6] == 'e' && step[7] == '.' && step[8] == 'p'
                 && step[9] == '.')
                && board[8 - step[5] + 48][step[4] - 97] == 'p'
                && board[8 - step[5] + 48 - 1][step[4] - 97] == 'P')
                board[8 - step[5] + 48 - 1][step[4] - 97] = ' ';
            else if (
                    (step[6] == 'e' && step[7] == '.' && step[8] == 'p'
                     && step[9] == '.')
                    && board[8 - step[5] + 48][step[4] - 97] == 'P'
                    && board[8 - step[5] + 48 + 1][step[4] - 97] == 'p')
                board[8 - step[5] + 48 + 1][step[4] - 97] = ' ';
            //Превращение.
            if (step[6] == 'K' || step[6] == 'Q' || step[6] == 'R'
                || step[6] == 'B' || step[6] == 'N') {
                if (board[8 - step[5] + 48][step[4] - 97] == 'P')
                    board[8 - step[5] + 48][step[4] - 97] = step[6];
                else
                    board[8 - step[5] + 48][step[4] - 97] = step[6] - 32;
            }
            //Мат.
            if (step[6] == '#')
                return 0;
            //Рокировка.
            if (step[6] == '0' && step[7] == '-' && step[8] == '0'
                && step[9] == '-' && step[10] == '0') {
                for (i = step[4] - 97; i < 8 && i >= 0;
                     i -= ((step[1] - step[4]) / abs(step[1] - step[4]))) {
                    if (board[8 - step[5] + 48][i] == 'R'
                                && board[8 - step[5] + 48][step[4] - 97] == 'K'
                        || board[8 - step[5] + 48][i] == 'r'
                                && board[8 - step[5] + 48][step[4] - 97]
                                        == 'k') {
                        board[8 - step[5] + 48]
                             [step[4] - 97
                              + ((step[1] - step[4]) / abs(step[1] - step[4]))]
                                = board[8 - step[5] + 48][i];
                        board[8 - step[5] + 48][i] = ' ';
                        break;
                    }
                }
            } else if (step[6] == '0' && step[7] == '-' && step[8] == '0') {
                board[8 - step[5] + 48]
                     [step[4] - 97
                      + ((step[1] - step[4]) / abs(step[1] - step[4]))]
                        = board[8 - step[5] + 48]
                               [step[4] - 97
                                - ((step[1] - step[4])
                                   / abs(step[1] - step[4]))];
                board[8 - step[5] + 48]
                     [step[4] - 97
                      - ((step[1] - step[4]) / abs(step[1] - step[4]))]
                        = ' ';
            }
        } else
            return 1;
    } else {
        //Проверка типа хода.
        if (!((board[8 - step[4] + 48][step[3] - 97] == ' ' && step[2] == '-')
              || (board[8 - step[4] + 48][step[3] - 97] != ' '
                  && step[2] == 'x'))) {
            return 3;
        }
        //Проверка диапазона.
        if ((step[3] >= 97 && step[3] <= 104)
            && (step[4] >= 49 && step[4] <= 56)) {
            //Перемещение фигуры.
            board[8 - step[4] + 48][step[3] - 97]
                    = board[8 - step[1] + 48][step[0] - 97];
            board[8 - step[1] + 48][step[0] - 97] = ' ';
            //Взятие на проходе.
            if ((step[5] == 'e' && step[6] == '.' && step[7] == 'p'
                 && step[8] == '.')
                && board[8 - step[4] + 48][step[3] - 97] == 'p'
                && board[8 - step[4] + 48 - 1][step[3] - 97] == 'P')
                board[8 - step[4] + 48 - 1][step[3] - 97] = ' ';
            else if (
                    (step[5] == 'e' && step[6] == '.' && step[7] == 'p'
                     && step[8] == '.')
                    && board[8 - step[4] + 48][step[3] - 97] == 'P'
                    && board[8 - step[4] + 48 + 1][step[3] - 97] == 'p')
                board[8 - step[4] + 48 + 1][step[3] - 97] = ' ';
            //Превращение.
            if (step[5] == 'K' || step[5] == 'Q' || step[5] == 'R'
                || step[5] == 'B' || step[5] == 'N') {
                if (board[8 - step[4] + 48][step[3] - 97] == 'P')
                    board[8 - step[4] + 48][step[3] - 97] = step[5];
                else
                    board[8 - step[4] + 48][step[3] - 97] = step[5] - 32;
            }
            //Мат.
            if (step[5] == '#')
                return 0;
            //Рокировка.
            if (step[5] == '0' && step[6] == '-' && step[7] == '0'
                && step[8] == '-' && step[9] == '0') {
                for (i = step[3] - 97; i < 8 && i >= 0;
                     i -= ((step[0] - step[3]) / abs(step[0] - step[3]))) {
                    if (board[8 - step[4] + 48][i] == 'R'
                                && board[8 - step[4] + 48][step[3] - 97] == 'K'
                        || board[8 - step[4] + 48][i] == 'r'
                                && board[8 - step[4] + 48][step[3] - 97]
                                        == 'k') {
                        board[8 - step[4] + 48]
                             [step[3] - 97
                              + ((step[0] - step[3]) / abs(step[0] - step[3]))]
                                = board[8 - step[4] + 48][i];
                        board[8 - step[4] + 48][i] = ' ';
                        break;
                    }
                }
            } else if (step[5] == '0' && step[6] == '-' && step[7] == '0') {
                board[8 - step[4] + 48]
                     [step[3] - 97
                      + ((step[0] - step[3]) / abs(step[0] - step[3]))]
                        = board[8 - step[4] + 48]
                               [step[3] - 97
                                - ((step[0] - step[3])
                                   / abs(step[0] - step[3]))];
                board[8 - step[4] + 48]
                     [step[3] - 97
                      - ((step[0] - step[3]) / abs(step[0] - step[3]))]
                        = ' ';
            }
        } else
            return 1;
    }
    return 999;
}

int main()
{
    int result;
    while (1) {
        printBoard();
        result = scanStep();
        if (!result) { //Завершение.
            printBoard();
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
