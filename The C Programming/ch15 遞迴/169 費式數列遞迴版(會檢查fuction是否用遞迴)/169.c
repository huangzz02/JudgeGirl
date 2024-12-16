#include <stdio.h>

// fibr.h
int fibr(int n);

// fibr.c
int fibr(int n) {
    if (n == 0 || n == 1) return 1; // a0, a1, a2, ... , an
    return fibr(n - 1) + fibr(n - 2);
}

// main.c
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", fibr(n));
}