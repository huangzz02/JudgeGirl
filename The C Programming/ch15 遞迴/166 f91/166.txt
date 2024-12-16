#include <stdio.h>

// f91.h
int f91(int n);

// f91.c
int f91(int n) {
    if (n >= 101) return n - 10;
    if (n <= 100) return f91(f91(n + 11));
}

// main.c
int main(){
    int n;
    scanf("%d", &n);
    printf("f91(%d) = %d\n", n, f91(n));
    return 0;
}