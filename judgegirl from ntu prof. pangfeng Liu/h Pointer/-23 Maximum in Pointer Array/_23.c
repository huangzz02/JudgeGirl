#include <stdio.h>

// max.h
int max(int *iptr[], int n);

// max.c
int max(int *iptr[], int n) {
    int max = -1;
    int i;
    for (i = 0; i < n; i++) {
        if (*iptr[i] > max) {
            max = *iptr[i];
        }
    }
    return max;
}

// main.c
int main() {
    int n, i;
    int array[100];
    int *iptr[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &(array[(i + 3) % n]));
        iptr[i] = &(array[(i + 3) % n]);
    }
    printf("%d\n", max(iptr, n));
    return 0;
}