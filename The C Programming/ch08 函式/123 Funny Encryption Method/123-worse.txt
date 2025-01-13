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
    char N_str[100];
    sprintf(N_str, "%d", N);
    int length = 0;
    while (N_str[length] != '\0') {
        length++;
    }

    int dec_N = 0;
    for (int i = 0; i < length; i++) {
        dec_N = dec_N*16 + (N_str[i]-'0');
    }

    int s = bin(dec_N);
    return s;
}
/*
    hex to dec to bin
    worse solution
*/

//main.c
int main() {
    int N, b1, b2;
    scanf("%d", &N);
    b1 = bin(N);
    b2 = hex(N);
    printf("%d %d", b1, b2);
    return 0;
}