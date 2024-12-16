#include <stdio.h>

int main(){
    
    int n;
    scanf("%d", &n);
    
    int i = 0, x, y;
    while (n - i * i > 0) {
        i++;
    }
    if (i % 2 != 0) { //i -> odd
        if (n - (i - 1) * (i - 1) <= i) {
            x = i;
            y = n - (i - 1) * (i - 1);
        } else {
            x = (i * i - n) + 1;
            y = i;
        }
    } else { //i -> even
        if (n - (i - 1) * (i - 1) <= i) {
            x = n - (i - 1) * (i - 1);
            y = i;
        } else {
            x = i;
            y = (i * i - n) + 1;
        }
    }
    
    printf("%d %d\n", x, y);
    
    return 0;
}