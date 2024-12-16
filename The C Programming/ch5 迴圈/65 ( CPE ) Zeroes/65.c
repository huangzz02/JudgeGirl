#include <stdio.h>

int main(void) {
    while (1) {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        
        if (a == 0 && b == 0) {
            break;
        }

        int count = 1;

        while ((a % 5 != b % 5)) {
            a++;
            
            if (a % 5 == 0) {
                count++;
            }
        }
        
        count += (b - a) / 5;

        printf("%d\n", count);
    }

    return 0;
}