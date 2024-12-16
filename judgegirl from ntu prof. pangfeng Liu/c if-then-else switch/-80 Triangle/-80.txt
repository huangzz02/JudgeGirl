#include <stdio.h>
#include <math.h>

int main() {
    
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2, x3, y3;
        scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
        
        double a, b, c;
        a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
        c = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
        
        double tem;
        if (b < a) {
            tem = b;
            b = a;
            a = tem;
        }
        if (c < a) {
            tem = c;
            c = a;
            a = tem;
        }
        if (c < b) {
            tem = c;
            c = b;
            b = tem;
        }
        //a < b < c
        
        if (fabs(a - b) < 1e-6 || fabs(b - c) < 1e-6 || fabs(a - c) < 1e-6) {
            printf("isosceles\n");
        } else if (fabs(a * a + b * b - c * c) < 1e-6) {
            printf("right\n");
        }else if (a * a + b * b < c * c) {
            printf("obtuse\n");
        } else if (a * a + b * b > c * c) {
            printf("acute\n");
        }
    }

    return 0;
}