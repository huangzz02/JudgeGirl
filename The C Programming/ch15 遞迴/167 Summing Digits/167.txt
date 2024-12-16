#include <stdio.h>

// f.h
int f(int n);

// f.c
int f(int n) {
    if (n < 10) {
        return n;
    } else {
        return f(f(n / 10) + n % 10);
    }
}

// main.c
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", f(n));    
    return 0;
}