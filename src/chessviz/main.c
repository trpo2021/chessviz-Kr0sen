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
        if (result == EXIT_SUCCESS) {
            print_board(board);
            return EXIT_SUCCESS;
        }
        if (result == ERROR_OUT_OF_RANGE) {
            printf("\nВыход за пределы доски.\n");
            return ERROR_OUT_OF_RANGE;
        }
        if (result == ERROR_DIFFERENT_FIGURES) {
            printf("\nФигура не соответствует фактической.\n");
            return ERROR_DIFFERENT_FIGURES;
        }
        if (result == ERROR_WRONG_MOVE_TYPE) {
            printf("\nНеверный тип хода.\n");
            return ERROR_WRONG_MOVE_TYPE;
        }
    }
}