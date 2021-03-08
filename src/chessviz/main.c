#include <libchessviz/board_print_plain.h>
#include <libchessviz/constants.h>
#include <libchessviz/fill_board_std.h>
#include <libchessviz/scan.h>
#include <stdio.h>

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