#include <stdio.h>

#define N 4 //change this

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int position(int board[N][N], int row, int col) {
    for (int i = 0; i < N; i++) {
        if (board[row][i] == 1 || board[i][col] == 1) {
            return 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i + j == row + col || i - j == row - col) && board[i][j] == 1) {
                return 0;
            }
        }
    }
    return 1;
}

int solve(int board[N][N], int row) {
    if (row == N) {
        printBoard(board);
        return 1;
    }

    for (int col = 0; col < N; col++) {
        if (position(board, row, col)) {
            board[row][col] = 1;

            if (solve(board, row + 1)) {
                return 1;
            }

            board[row][col] = 0;
        }
    }

    return 0;
}

void nQueens() {
    int board[N][N] = {0};

    solve(board, 0);
}

int main() {
    nQueens();

    return 0;
}
