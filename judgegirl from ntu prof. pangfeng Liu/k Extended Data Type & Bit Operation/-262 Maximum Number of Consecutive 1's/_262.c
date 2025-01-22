#include <stdio.h>

int countMax(int n) {
    int maxCount = 0;
    int currentCount = 0;

    while (n > 0) {
        if (n & 1) {
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        } else {
            currentCount = 0;
        }
        n >>= 1;
    }

    return maxCount;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", countMax(n));
    }
    return 0;
}