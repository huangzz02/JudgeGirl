#include <stdio.h>
#include <stdlib.h>

//mul.h
void mul(int a[3][3], int b[3][3], int c[3][3]);

//mul.c
void mul(int a[3][3], int b[3][3], int c[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            c[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

//main.c
int main(){
    int a[3][3], b[3][3], c[3][3], i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &b[i][j]);
        }
    }
 
    mul(a, b, c);
 
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}