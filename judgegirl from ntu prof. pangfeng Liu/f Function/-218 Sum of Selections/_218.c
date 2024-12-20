#include <stdio.h>

int combination(int n, int m) {
    int num = 1, den = 1;
    for(int i = 0; i < m; i++) {
        num *= (n - i);
        den *= (i + 1);
    }
    return num / den;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int s = 0;
    for (int i = 0; i <= m; i++) {
        s += combination(n, i);
    }
    printf("%d\n", s);
    return 0;
}