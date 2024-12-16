#include <stdio.h>
#include <stdbool.h>

int main() {
    int y, m, d, s=0;
    scanf("%d %d %d", &y, &m, &d);

    bool k = ( y % 4 == 0 && y % 100 != 0 ) || y % 400 == 0;
    
    for (int i = 1; i < m; i++) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            s += 31;
        }else if (i == 2) {
            if (k) {
                s += 29;
            } else {
                s += 28;
            }
        }else {
            s += 30;
        }
    }
    s += d;
    
    printf("%d\n", s);
    return 0;
}