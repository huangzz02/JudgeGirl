#include <stdio.h>

int is_prime (int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int reverse (int n) {
    int rev_n = 0;
    while (n > 0) {
        int last = n % 10;
        rev_n = rev_n * 10 + last;
        n /= 10;
    }
    return rev_n;
}

int main(){
    int m;
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        int n;
        scanf("%d", &n);
        
        if (!is_prime(n)) {
            printf("%d is not prime.\n", n);
        } else if (!is_prime(reverse(n)) || reverse(n) == n) {
            printf("%d is prime.\n", n);
        } else {
            printf("%d is emirp.\n", n);
        }
    }
    
    return 0;
}