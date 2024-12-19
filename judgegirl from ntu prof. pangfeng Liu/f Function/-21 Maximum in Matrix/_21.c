#include <stdio.h>

// max.h
int max(int array[5][5]);

// max.c
int max(int array[5][5]) {
    int k = -1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (array[i][j] > k) k = array[i][j];
        }
    }
    return k;
}

// main.c
int main() {
    int i, j;
    int array[5][5];
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &(array[i][j]));
        }
    }
    printf("%d\n", max(array));
    return 0;
}