#include <stdio.h>

//bin.h
int bin(int N);

//bin.c
int bin(int N) {
    int s = 0;
    while (N > 0) {
        if (N % 2 == 1) s++;
        N /= 2;
    }
    return s;
}

//hex.h
int hex(int N);

//hex.c
int hex(int N) {
    int s = 0;
    while (N > 0) {
        s += bin(N % 10);
        N /= 10;
    }
    return s;
}

//main.c
int main() {
    int N, b1, b2;
    scanf("%d", &N);
    b1 = bin(N);
    b2 = hex(N);
    printf("%d %d", b1, b2);
    return 0;
}