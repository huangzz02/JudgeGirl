#include <stdio.h>

// evaluate_f.h
int evaluate_f(int *iptr[], int n, int *index);

// evaluate_f.c
int evaluate_f(int *iptr[], int n, int *index) {
    int max;
    for (int i = 0; i < n; i++) {
        int sum = 4 * iptr[i][0] - 6 * iptr[i][1];
        if (i == 0 || sum > max) {
            max = sum;
            *index = i;
        }
    }
    return max;
}

// test.c
int main(){
    int a[] = { 9, 7 };
    int b[] = { 3, 2 };
    int c[] = { 3, 2 };
    int d[] = { 9, 7 };
    int *iptr[] = { a, b, c, d };
    int max, index;
    max = evaluate_f(iptr, 4, &index);
    printf("%d %d\n", max, index);
}
