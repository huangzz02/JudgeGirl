#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, m;
    scanf("%d", &n);

    int data[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    scanf("%d", &m);

    int sum[m];
    for (int i = 0; i < m; i++) {
        sum[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int place = data[i] % m;
        sum[place]++;
    }

    for (int i = 0; i < m; i++) {
        printf("%d\n", sum[i]);
    }

    return 0;
}