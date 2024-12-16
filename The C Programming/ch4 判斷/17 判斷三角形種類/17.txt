#include <stdio.h>

int main() {
    int a, b, c, tem = 0;
    scanf("%d %d %d", &a, &b, &c);

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
        printf("not a triangle\n");
    } else if (a == b && b == c) {
        printf("regular triangle\n");
    } else if (a * a + b * b == c * c) {
        printf("rectangular triangle");
    } else if (a * a + b * b < c * c) {
        if (a == b) {
            printf("isosceles obtuse triangle");
        } else {
            printf("obtuse triangle");
        }
    } else if (a * a + b * b > c * c) {
        if (a == b || b == c) {
            printf("isosceles acute triangle");
        } else {
            printf("acute triangle");
        }
    }

    return 0;
}