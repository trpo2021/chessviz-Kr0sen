#include <stdio.h>
#include <stdlib.h>

char board[8][8]
        = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
           {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
           {
                   ' ',
                   ' ',
                   ' ',
                   ' ',
                   ' ',
                   ' ',
                   ' ',
                   ' ',
           },
           {
                   ' ',
                   ' ',
                   ' ',
                   ' ',
                   ' ',
                   ' ',
                   ' ',
                   ' ',
           },
           {
                   ' ',
                   ' ',
                   ' ',
                   ' ',
                   ' ',
                   ' ',
                   ' ',
                   ' ',
           },
           {
                   ' ',
                   ' ',
                   ' ',
                   ' ',
                   ' ',
                   ' ',
                   ' ',
                   ' ',
           },
           {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
           {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

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

int main()
{
    int enter;
    printf("1.Print board\n2.Exit\n");
    while (1) {
        scanf("%d", &enter);
        switch (enter) {
        case 1:
            printBoard();
            break;
        case 2:
            goto exit;
        }
    }
exit:
    return 0;
}
