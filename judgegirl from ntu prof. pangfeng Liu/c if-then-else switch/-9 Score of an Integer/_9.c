#include <stdio.h>

int main() {
    
    int x, sc = 0;
    scanf("%d", &x);
    
    if (x <= 0) {
        sc = -100;
    } else {
        if (x % 3 == 0) {
            sc += 3;
        }
        if (x % 5 == 0) {
            sc += 5;
        } 
        if (x >= 100 && x <= 200) {
            sc += 50;
        } else {
            sc -= 50;
        }
    }
    
    printf("%d\n", sc);

    return 0;
}