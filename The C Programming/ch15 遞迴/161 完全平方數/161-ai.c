#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// rangePerfectSquare.h
bool rangePerfectSquare(int, int, int);

// rangePerfectSquare.c
bool rangePerfectSquare(int left, int right, int target) {
    if (left > right) {
        return false;
    }

    int mid = left + (right - left) / 2; // prevent overflow
    if (mid == sqrt(target)) { // prevent overflow
        return true;
    }
    else if (mid < sqrt(target)) { // prevent overflow
        return rangePerfectSquare(mid + 1, right, target);
    }
    else {
        return rangePerfectSquare(left, mid - 1, target);
    }
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