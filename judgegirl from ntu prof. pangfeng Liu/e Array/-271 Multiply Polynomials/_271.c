#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int data1[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &data1[i]);
    }
    int m;
    scanf("%d", &m);
    int data2[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &data2[i]);
    }

    int ans[n + m - 1];
    for (int i = 0; i < n + m - 1; i++) {
        ans[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i + j] += data1[i] * data2[j];
        }
    }

    for (int i = 0; i < n + m - 1; i++) {
        printf("%d", ans[i]);
        if (i < n + m - 2) printf(" ");
    }
    printf("\n");
    
    return 0;
}