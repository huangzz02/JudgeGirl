#include <stdio.h>

int main(){
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        if (m == 0 || m == 1) {
            printf("Boring!\n");
            continue;
        }
        
        int out = 0;
        int test_n = n;
        while (test_n != 1) {
            if (test_n % m == 0) {
                test_n /= m;
            } else {
                out = 1;
                break;
            }
        }
        
        if (out) {
            printf("Boring!\n");
        } else {
            while (n != 1) {
                printf("%d ", n);
                n /= m;
            }
            
            printf("1\n");
        }
    }

    return 0;
}