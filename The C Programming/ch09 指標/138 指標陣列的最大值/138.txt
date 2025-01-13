#include <stdio.h>

//max.h
int max(int* iptr, int n);

//max.c
int max(int* iptr, int n) {
    iptr = iptr - n;
    int max = *iptr;
    for (int i = 1; i < n; i++) {
        if (*(iptr + i) > max) {
            max = *(iptr + i);
        }
    }
    return max;
}

//main.c
int main() {
    int n, i;
    int array[100];
    int* iptr;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &(array[i]));
        iptr = &(array[i]);
        iptr++;
    }
    printf("%d\n", max(iptr, n));
    return 0;
}