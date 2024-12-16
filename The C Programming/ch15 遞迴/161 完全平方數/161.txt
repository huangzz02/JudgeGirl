#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

// rangePerfectSquare.h
bool rangePerfectSquare(int, int, int);

// rangePerfectSquare.c
bool rangePerfectSquare(int left, int right, int target) {
    if (left * left > target) {
        return false;
    }
    if (left * left == target) {
        return true;
    }

    rangePerfectSquare(left + 1, right, target);
}

// main.c
int main() {
    int a;
    scanf("%d", &a);
    bool ans = rangePerfectSquare(1, INT_MAX, a);
    if (ans) {
        printf("true");
    }
    else {
        printf("false");
    }
    printf("\n");
    return 0;
}