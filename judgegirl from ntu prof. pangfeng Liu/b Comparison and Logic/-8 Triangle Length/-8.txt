#include <stdio.h>

int main() {
    int a, b, c, tem = 0;
    scanf("%d\n%d\n%d", &a, &b, &c);

    if (a > b) {
        tem = a;
        a = b;
        b = tem;
    } if (a > c) {
        tem = a;
        a = c;
        c = tem;
    } if (b > c) {
        tem = b;
        b = c;
        c = tem;
    }
  
    if (a + b <= c) {
        printf("0\n");
    } else {
        printf("1\n");
    }
    
    return 0;
}