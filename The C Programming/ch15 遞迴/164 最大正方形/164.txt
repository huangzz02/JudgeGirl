#include <stdio.h>
#include <stdlib.h>

// MaximalSquare.h
void findMaximalSquare(int** matrix, int rows, int cols, int *maxEdge);

// MaximalSquare.c
void findMaximalSquare(int** matrix, int rows, int cols, int *maxEdge) {
    if (rows == 0 || cols == 0) {
        for (int i = 0; i <= rows; i++) {
            for (int j = 0; j <= cols; j++) {
                if (matrix[i][j] >= 1 && *maxEdge == 0) {
                    *maxEdge = 1;
                }
            }
        }
        return;
    }

    int check = 0;

    for (int i = rows; i > 0; i--) {
        for (int j = cols; j > 0; j--) {
            if (matrix[i][j] >= 1 &&
                matrix[i][j] == matrix[i-1][j] &&
                matrix[i][j] == matrix[i][j-1] &&
                matrix[i][j] == matrix[i-1][j-1]) {
                    matrix[i][j] += 1;
            
                if (matrix[i][j] > *maxEdge) {
                    *maxEdge = matrix[i][j];
                    check = 1;
                }
            }
        }
    }

    if (check == 0) {
        return;
    } else {
        findMaximalSquare(matrix, rows, cols, maxEdge);
    }
}

// main.c
int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    int** matrix = (int**)malloc(row * sizeof(int*));
    int i, j, tmp;
    for (i = 0; i < row; i++) {
        matrix[i] = (int*)malloc(col * sizeof(int));
    }
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &tmp);
            matrix[i][j] = tmp;
        }
    }
 
    int maxEdge = 0;
    findMaximalSquare(matrix, row - 1, col - 1, &maxEdge);
 
    printf("%d", maxEdge * maxEdge);
    for (i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
}