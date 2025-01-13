#include <stdio.h>

long long reverse (long long a) {
    long long rev_a = 0;
    while (a > 0) {
        int digit = a % 10;
        rev_a = rev_a * 10 + digit;
        a /= 10;
    }
    return rev_a;
}

void find_smallest(int n) {
    if (n == 0) {
        printf("0\n");
        return;
    }
    if (n == 1) {
        printf("1\n");
        return;
    }
    
    int out = 0;
    long long rev_ans = 0;
    
    while (n > 1) {
        int ori_n = n;
        for (int i = 9; i > 1; i--) {
            if (n % i == 0) {
                n /= i;
                rev_ans = rev_ans * 10 + i;
                break;
            }
        }
        if (n == ori_n) {
            out = 1;
            break;
        }
    }
    
    if (out) {
        printf("-1\n");
        return;
    } else {
        printf("%lld\n", reverse(rev_ans));
        return;
    }
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        
        find_smallest(n);
    }

    return 0;
}