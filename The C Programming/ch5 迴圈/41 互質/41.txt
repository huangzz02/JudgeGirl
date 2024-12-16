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
            fac = i;
        }
    }
    if (fac == 1) {
        printf("兩數互質\n");
    } else {
        printf("兩數不互質\n");
    }
    
    return 0;
}