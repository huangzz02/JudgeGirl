#include <stdio.h>

// posneg.h
void posneg(int array[5][5], int result[2]);

// posneg.c
void posneg(int array[5][5], int result[2]) {
    int negative = 0, positive = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (array[i][j] < 0) negative++;
            else if (array[i][j] > 0) positive++;
        }
    }
    result[0] = negative;
    result[1] = positive;
}

// main.c
int main() {
    int i, j;
    int array[5][5];
    int result[2];
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            scanf("%d", &array[i][j]);
   
    posneg(array, result);
    printf("%d\n", result[0]);
    printf("%d\n", result[1]);
    return 0;
}