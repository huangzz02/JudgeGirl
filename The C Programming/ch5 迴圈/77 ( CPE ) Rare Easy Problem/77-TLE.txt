#include <stdio.h>
#include <math.h>

int main() {
    long long x;
    
    while (scanf("%d", &x) == 1) {
        if (x == 0) break;

        int digit = (int)log10(x) + 1;

        long long min = (long long)pow(10, digit-1);
        long long max = (long long)pow(10, digit+1) - 1;
        
        long long m;
        int count = 0;
        for (long long n = min; n < max; n++) {
            m = n / 10;
            if (n - m == x) {
                if (count == 0) {
                    printf("%lld", n);
                    count = 1;
                } else {
                    printf(" %lld", n);
                }
            }
        }

        printf("\n");
    }
    
    return 0;
}
// TLE (bad solution)

// ex : x is 5 digit

//! 5 + a = ab, ab - a = 1 ~ 2
//! 5 + ab = abc, abc - ab = 2 ~ 3
//! 5 + abc = abcd, abcd - abc = 3 ~ 4
//* 5 + abcd = abcde, abcde - abcd = 4 ~ 5
//* 5 + abcde = abcdef, abcdef - abcde = 5 ~ 6
//! 5 + abcdef = abcdefg, abcdefg - abcdef = 6 ~ 7

// search from 10000 ~ 999999