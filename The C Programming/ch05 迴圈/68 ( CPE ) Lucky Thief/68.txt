#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
        
    for (int i = 0; i < t; i++) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        int digit = m - 1;
        long long sum = 0;
        
        if (n == m) {
            for (int j = 1; j < n; j++) {
                sum += j;
            }
            
        } else {
            for (int j = 0; j < n; j++) {
                sum += digit;
                digit--;
            }
        }
        
        printf("%lld\n", sum);
    }

    return 0;
}