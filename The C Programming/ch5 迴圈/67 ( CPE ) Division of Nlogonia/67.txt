#include <stdio.h>

int main() {
    while (1) {
        int n;
        scanf("%d", &n);
        
        if (n == 0) {
            break;
        }
        
        int div_x, div_y;
        scanf("%d %d", &div_x, &div_y);
            
        for (int k = 0; k < n; k++) {
            int x, y;
            scanf("%d %d", &x, &y);
            
            if (x == div_x || y == div_y) {
                printf("divisa\n");
            } else if (x < div_x && y > div_y) {
                printf("NO\n");
            } else if (x > div_x && y > div_y) {
                printf("NE\n");
            } else if (x > div_x && y < div_y) {
                printf("SE\n");
            } else if (x < div_x && y < div_y) {
                printf("SO\n");
            }
        }
    }

    return 0;
}