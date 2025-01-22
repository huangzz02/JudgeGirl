#include <stdio.h>

int countMax(long long int n) {
    int count = 0;

    while (n > 0) {
        if (n & 1) count++;
        n >>= 1;
    }

    return count;
}

int main() {
    long long int n;
    while (scanf("%lld", &n) != EOF) {
        printf("%d\n", countMax(n));
    }
    return 0;
}