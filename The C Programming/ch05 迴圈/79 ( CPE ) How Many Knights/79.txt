#include <stdio.h>

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) == 2) {
        if (m == 0 && n == 0) break;
        
        int ori_m = m, ori_n = n;
        int s = 0;
        if (m > n) {
            int temp = m;
            m = n;
            n = temp;
        }

        if (m == 1) {
            s = n;
        } else if (m == 2) {
            s = (n / 4) * 4;
            if (n % 4 == 1) {
                s += 2;
            } else if (n % 4 == 2 || n % 4 == 3) {
                s += 4;
            }
        } else {
            if ((m % 2 == 0) || (n % 2 == 0)) {
                s = (m * n) / 2;
            } else {
                s = (m * n + 1) / 2;
            }
        }

        printf("%d knights may be placed on a %d row %d column board.\n", s, ori_m, ori_n);
    }
    return 0;
}