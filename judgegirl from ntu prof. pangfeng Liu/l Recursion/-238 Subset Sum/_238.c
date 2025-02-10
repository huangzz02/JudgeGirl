#include <stdio.h>

int n, k;
int data[15];

int solve(int i, int sum) {
    if (i == n) {
        if (sum == k) {
            return 1;
        } else {
            return 0;
        }
    }

    return solve(i + 1, sum + data[i]) + solve(i + 1, sum);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    while (scanf("%d", &k) != EOF) {
        printf("%d\n", solve(0, 0));
    }

    return 0;
}