#include <stdio.h>
#include <stdlib.h>

// GCD.h
int GCD(int t, int v);

// GCD.c
int GCD(int t, int v) {
    if (t % v == 0) {
        return v;
    }
    return GCD(v, t % v);
}

// main.c
int main() {
    int a, b;
 
    scanf("%d", &a);
    scanf("%d", &b);
    int temp;
 
    if (b > a) {
        temp = a;
        a = b;
        b = temp;
    }
    printf("%d\n", GCD(a, b));
    return 0;
}