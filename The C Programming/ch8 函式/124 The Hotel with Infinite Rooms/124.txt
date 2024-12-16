#include <stdio.h>

//D_size.h
int D_size(int S, int D);

//D_size.c
int D_size(int S, int D) {
    S--;
    while (D > 0) {
        S++;
        D -= S;
    }
    return S;
}

//main.c
int main(){
    int S, D;
    scanf("%d %d", &S, &D);
    printf("%d", D_size(S, D));
    return 0;
}