#include <stdio.h>
#include <stdbool.h>

int check_m (int m, bool k) {
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        return 31;
    }else if (m == 2) {
        return k ? 29 : 28;
    }else {
        return 30;
    }
}

int main() {
    int y, dw;
    scanf("%d %d", &y, &dw);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int m, d;
        scanf("%d %d", &m, &d);

        bool k = ( y % 4 == 0 && y % 100 != 0 ) || y % 400 == 0;
        int s = 0;

        if (m < 1 || m > 12) {
            printf("-1\n");
            continue;
        }
          
        for (int i = 1; i < m; i++) {
            s += check_m(i, k);
        }

        if (d < 1 || d > check_m(m, k)) {
            printf("-2\n");
            continue;
        } else {
            s += d;
        }

        int tem_dw = dw;
        s %= 7;
        tem_dw += s - 1;
        if (tem_dw > 6) {
            tem_dw -= 7;
        } 
          
        printf("%d\n", tem_dw);
    }

    return 0;
}