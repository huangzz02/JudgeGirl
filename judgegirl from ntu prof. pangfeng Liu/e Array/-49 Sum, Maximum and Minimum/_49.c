#include <stdio.h>
#include <limits.h>

int main() {
    int N, m;
    scanf("%d %d", &N, &m);

    int sum[m], max[m], min[m];
    for (int i = 0; i < m; i++) {
        sum[i] = 0;
        max[i] = INT_MIN;
        min[i] = INT_MAX;
    }

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);

        int place = x % m;
        sum[place] += x;
        if (x > max[place]) max[place] = x;
        if (x < min[place]) min[place] = x;
    }

    for (int i = 0; i < m; i++) {
        printf("%d %d %d\n", sum[i], max[i], min[i]);
    }
    
    return 0;
}