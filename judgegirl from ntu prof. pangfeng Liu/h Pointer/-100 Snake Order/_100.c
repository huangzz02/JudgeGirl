#include <stdio.h>
#include <assert.h>

// snake.h
void snake(const int *ptr_array[100][100], int m);

// snake.c
void snake(const int *ptr_array[100][100], int m) {
    for (int i = 0; i < m * m - 1; i++) {
        for (int j = 0; j < m * m - 1 - i; j++) {
            int row1 = j / m, col1 = j % m;
            int row2 = (j + 1) / m, col2 = (j + 1) % m;

            if (*ptr_array[row1][col1] > *ptr_array[row2][col2]) {
                const int *temp = ptr_array[row1][col1];
                ptr_array[row1][col1] = ptr_array[row2][col2];
                ptr_array[row2][col2] = temp;
            }
        }
    }
    

    for (int i = 0; i < m; i++) {
        if (i % 2 != 0) {
            for (int j = 0; j < m / 2; j++) {
                const int *temp = ptr_array[i][j];
                ptr_array[i][j] = ptr_array[i][m - j - 1];
                ptr_array[i][m - j - 1] = temp;
            }
        }
    }
}

// main.c
int main() {
    int array[100][100], check[100][100];
    const int *ptr_array[100][100];
    int i, j, m;
 
    scanf("%d", &m);
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++) {
            ptr_array[i][j] = &(array[i][j]);
            scanf("%d", &(array[i][j]));
            check[i][j] = array[i][j];
        }
 
    snake(ptr_array, m);
 
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            assert(check[i][j] == array[i][j]);
            assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
            printf("%d ", *(ptr_array[i][j]));
        }
        printf("\n");
    }
 
    return 0;
}