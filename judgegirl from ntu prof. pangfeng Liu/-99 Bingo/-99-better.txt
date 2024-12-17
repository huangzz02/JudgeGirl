#include <stdio.h>
#include <stdlib.h>

typedef struct player_data {
    char name[64];
    int rows;
    int cols;
    int **board;
} player_data;

int checkMatrix(int **matrix, int m, int ii, int jj) {
    // 1. rows
    int check_rows = 1;
    for (int j = 0; j < m; j++) {
        if (matrix[ii][j] != 0) {
            check_rows = 0;
            break;
        }
    }
    if (check_rows == 1) {
        return 1;
    }

    // 2. cols
    int check_cols = 1;
    for (int i = 0; i < m; i++) {
        if (matrix[i][jj] != 0) {
            check_cols = 0;
            break;
        }
    }
    if (check_cols == 1) {
        return 1;
    }


    // 3. main diagonal
    int check_main_diagonal = 1;
    if (ii == jj) {
        for (int i = 0; i < m; i++) {
            if (matrix[i][i] != 0) {
                check_main_diagonal = 0;
                break;
            }
        }
        if (check_main_diagonal == 1) {
            return 1;
        }
    }

    // 4. secondary diagonal
    int check_secondary_diagonal = 1;
    if (ii + jj == m - 1) {
        for (int i = 0; i < m; i++) {
            if (matrix[i][m - 1 - i] != 0) {
                check_secondary_diagonal = 0;
                break;
            }
        }
        if (check_secondary_diagonal == 1) {
            return 1;
        }
    }

    // if tests all fails
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    player_data players[n];

    for (int i = 0; i < n; i++) {
        scanf("%s", players[i].name);

        players[i].board = (int **)malloc(m * sizeof(int *));
        for (int j = 0; j < m; j++) {
            players[i].board[j] = (int *)malloc(m * sizeof(int));
        }

        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                scanf("%d", &players[i].board[j][k]);
            }
        }
    }

    int data[m * m];
    for (int i = 0; i < m * m; i++) {
        scanf("%d", &data[i]);
    }

    for (int i = 0; i < m * m; i++) { // data
        int number_check = 0;
        for (int j = 0; j < n; j++) { // players
            int break_check = 0;
            int ii = 0, jj = 0;
            for (int k = 0; k < m; k++) { // rows
                for (int l = 0; l < m; l++) { // cols
                    if (data[i] == players[j].board[k][l]) {
                        players[j].board[k][l] = 0;
                        ii = k;
                        jj = l;
                        break_check = 1;
                        break;
                    }
                }
                if (break_check == 1) break;
            }

            if (checkMatrix(players[j].board, m, ii, jj) == 1) {
                if (number_check == 0) {
                    printf("%d", data[i]);
                    number_check = 1;
                }
                printf(" %s", players[j].name);
            }
        }
        if (number_check == 1) {
            printf("\n");
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    free(players[j].board[k]);
                }
                free(players[j].board);
            }
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            free(players[i].board[j]);
        }
        free(players[i].board);
    }

    return 0;
}