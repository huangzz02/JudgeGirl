#include <stdio.h>

int countMax(int n) {
    int count = 0;

    while (n > 0) {
        if (n & 1) count++;
        n >>= 1;
    }

    return count;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", countMax(n));
    }
    return 0;
}