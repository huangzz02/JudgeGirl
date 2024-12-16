#include <stdio.h>

int x_domain (int m, int x) {
    if (x > m - 1) {
        x = 0;
    }
    return x;
}

int y_domain (int n, int y) {
    if (y > n - 1) {
        y = 0;
    }
    return y;
}

int main() {
    int m, n, x1, y1, e1, n1, f1, x2, y2, e2, n2, f2;
    scanf("%d  %d   %d   %d   %d   %d   %d   %d   %d   %d   %d   %d",
           &m, &n, &x1, &y1, &e1, &n1, &f1, &x2, &y2, &e2, &n2, &f2);
    
    int original_e1 = e1;
    int original_n1 = n1;
    int original_e2 = e2;
    int original_n2 = n2;
    
    int count = 0;
    
    while (f1 > 0 || f2 > 0) {
        while (f1 > 0) {
            if (n1 > 0) {
                y1++;
                n1--;
                f1--;
                break;
            } else if (e1 > 0) {
                x1++;
                e1--;
                f1--;
                break;
            } else {
                e1 = original_e1;
                n1 = original_n1;
            }
        }
        
        x1 = x_domain(m, x1);
        y1 = y_domain(n, y1);
        
        while (f2 > 0) {
            if (e2 > 0) {
                x2++;
                e2--;
                f2--;
                break;
            } else if (n2 > 0) {
                y2++;
                n2--;
                f2--;
                break;
            } else {
                e2 = original_e2;
                n2 = original_n2;
            }
        }
        
        x2 = x_domain(m, x2);
        y2 = y_domain(n, y2);
        
        count++;
        
        if (x1 == x2 && y1 == y2) {
            printf("robots explode at time %d\n", count);
            return 0;
        }
    }
    
    printf("robots will not explode\n");
    
    return 0;
}