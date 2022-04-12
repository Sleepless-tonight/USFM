//
// Created by shili on 2022/4/7.
//
#include "stdio.h"
#include "stdarg.h"

# define __STDC_WANT_LIB_EXT1__ 1
# define SIZE 6
const char comp_c = '@';
const char player_c = 'O';

void display(char board[][SIZE]);

void reset_board(char board[][SIZE]);

int main(void) {

    char board[SIZE][SIZE] = {0};

    char again = 0;// Prompt for how to play
    printf("\nREVERSI\n\n");
    printf("You can go first on the first game, then we will take turns.\n");
    printf(" You will be white - (%C).\n I will be black - (%c).\n", player_c, comp_c);
    printf("Select a square for your move by typing a digit for the row\n "
           "and a letter for the column with no spaces between. \n");
    printf("\nGood luck! Press Enter to start.\n");
    scanf_s("%c", &again, sizeof(again));
    fflush(stdin);                                                                                  // Clear the buffer

    return 0;
}

