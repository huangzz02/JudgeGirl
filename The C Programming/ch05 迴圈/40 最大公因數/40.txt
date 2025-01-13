#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    
    int temp;
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    } // a < b
    
    int fac = 1;
    for (int i = 1; i <= a; i++) {
        if (a % i == 0 && b % i == 0) {
            if (i == 1) {
                printf("%d", i);
            } else {
                printf(" %d", i);
                fac = i;
            }
        }
    }
    printf("\n%d\n", fac);
    
    return 0;
}