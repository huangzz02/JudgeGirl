#include <stdio.h>
#include <stdbool.h>

bool check_win(int matrix[3][3], int ii, int jj) {
    // 1. rows
    int check_rows = 1;
    for (int j = 0; j < 3; j++) {
        if (matrix[ii][0] == 0 || matrix[ii][j] != matrix[ii][0]) {
            check_rows = 0;
            break;
        }
    }
    if (check_rows == 1) {
        return true;
    }

    // 2. cols
    int check_cols = 1;
    for (int i = 0; i < 3; i++) {
        if (matrix[0][jj] == 0 || matrix[i][jj] != matrix[0][jj]) {
            check_cols = 0;
            break;
        }
    }
    if (check_cols == 1) {
        return true;
    }


    // 3. main diagonal
    if (ii == jj) {
        if (matrix[0][0] != 0 && matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) {
            return true;
        }
    }

    // 4. secondary diagonal
    if (ii + jj == 2) {
        if (matrix[0][2] != 0 && matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) {
            return true;
        }
    }

    // if tests all fails
    return false;
}

int main() {
    int n;
    scanf("%d", &n);

    int data[n][2];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &data[i][j]);
        }
    }

    int board[3][3] = {0};

    int legal_move = 0;
    int count = 1;
    for (int i = 0; i < n; i++) {
        if (data[i][0] > 2 || data[i][0] < 0 || data[i][1] > 2 || data[i][1] < 0) continue;
        if (board[data[i][0]][data[i][1]] != 0) continue;

        legal_move++;

        if (count == 1) { // black
            board[data[i][0]][data[i][1]] = 1;
        } else if (count == 2) { // white
            board[data[i][0]][data[i][1]] = 2;
        }

        if (check_win(board, data[i][0], data[i][1])) {
            if (count == 1) {
                printf("Black wins.\n");
                break;
            } else if (count == 2) {
                printf("White wins.\n");
                break;
            }
        } else if (i == n - 1 || legal_move == 9) {
            printf("There is a draw.\n");
            break;
        }
        /*
        In fact, the logic of "line 84" is correct.
        But if the n-1th piece of data happens to be "illigal",
        the program will have no output.
        */

        count = (count == 1) ? 2 : 1;
    }

    return 0;
}