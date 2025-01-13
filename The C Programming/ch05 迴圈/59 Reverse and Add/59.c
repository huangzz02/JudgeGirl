#include <stdio.h>
#include <limits.h>

int palindrome (int n) {
    int reversed = 0;
    while (n > 0) {
        if (reversed > (INT_MAX - n % 10) / 10) {
            printf("overflow!\n");
            return -1;
        }
        
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    
    return reversed;
}

int main(){
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        
        int pal = palindrome(a);
        
        if (pal == -1) {
            continue;
        }
        
        if (a > INT_MAX - pal) {
            printf("overflow!\n");
            continue;
        }
        
        a += pal;
        int count = 1;
        
        while (1) {
            pal = palindrome(a);
            
            if (a == pal) {
                break;
            }
            
            if (pal == -1) {
                break;
            }
            if (a > INT_MAX - pal) {
                printf("overflow!\n");
                break;
            }
            
            a += pal;
            count++;
        }
        
        if (pal != -1 && a == pal) {
            printf("%d %d\n", count, a);
        }
    }
    
    return 0;
}