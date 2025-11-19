#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int total_abs = 0;
    int neg_count = 0;
    int min_abs = 101; // The problem guarantees |value| <= 100

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);

            total_abs += abs(x);
            if (x < 0) neg_count++;
            if (abs(x) < min_abs) min_abs = abs(x);
        }
    }

    if (neg_count % 2 == 0) {
        printf("%d\n", total_abs);
    } else {
        printf("%d\n", total_abs - 2 * min_abs);
    }

    return 0;
}