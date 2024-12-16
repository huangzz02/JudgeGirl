#include <stdio.h>

// fac.h
int fac(int n);

// fac.c
int fac(int n) {
    return n == 0 ? 1 : n * fac(n - 1);
}

// main.c
int main(){
    int n;
    scanf("%d", &n);
    printf("%d", fac(n));
    return 0;
}