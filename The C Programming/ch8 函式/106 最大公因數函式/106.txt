#include <stdio.h>

//gcd.h
void gcd(int a,int b);

//gcd.c
void gcd(int a,int b) {
    int ori_a = a, ori_b = b, temp;
    if (b > a) {
        temp = a;
        a = b;
        b = temp;
    }

    while (b > 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    printf("%d與%d的最大公因數為%d\n", ori_a, ori_b, a);
}
 
//main.c
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    gcd(a,b);
 
    return 0; 
}