#include <stdio.h>

int main() {
    int t, x, y;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &x, &y);
        int d = y - x;
        int step = 1, ans = 0, flag = 0;
        while (d > 0) {
            d -= step;
            ans++;
            if (flag) step++;
            flag = !flag;
            printf("%d %d\n", ans, step);
        }
        printf("%d\n", ans);
    }    
    return 0;
}

// 1 1 step
// 2 2 steps

// 3 3 steps
// 4 3 steps
// 5 4 steps
// 6 4 steps

// 7 5 steps
// 8 5 steps
// 9 5 steps
// 10 6 steps
// 11 6 steps
// 12 6 steps

// 13 7 steps
// 14 7 steps
// 15 7 steps
// 16 7 steps
// 17 9 steps
// 18 9 steps
// 19 9 steps
// 20 9 steps