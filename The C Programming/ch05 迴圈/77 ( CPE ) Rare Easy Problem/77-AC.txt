#include <stdio.h>

int main() {
    long long x;
    
    while (scanf("%lld", &x) == 1) {
        if (x == 0) break;

        long long n, m;
        int count = 0;
        for (int k = 9; k >= 0; k--) {
            if ((x - k) % 9 == 0) {
                m = (x - k) / 9;
                n = m*10 + k;
            
                if (n - m == x) {
                    if (count == 0) {
                        printf("%lld", n);
                        count = 1;
                    } else {
                        printf(" %lld", n);
                    }
                }
            }
        }

        printf("\n");
    }
    
    return 0;
}
// AC (better solution)

//N = 10M + k
//X = N - M = 10M + k - M
//M = (X - k) / 9