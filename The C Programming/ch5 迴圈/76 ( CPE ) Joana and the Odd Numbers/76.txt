#include <stdio.h>

int main() {
    long long n;
    while (scanf("%lld", &n) != EOF) {
        long long target = 1 + (n-1) / 2;
        target *= target;

        long long mid = ((target-1) * 2) - 1;
        printf("%lld\n", mid * 3);
    }
    return 0;
}