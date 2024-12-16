#include <stdio.h>

//getFib.h
void getFib(int N);

//getFib.c
void getFib(int N) {
    int a = 0, b = 1, temp;
    printf("%d", a);
    N--;

    while (N--) {
        printf(" %d", b);
        temp = a + b;
        a = b;
        b = temp;
    }
    printf("\n");
}

//main.c
int main() {
    int N;
    scanf("%d", &N);
    getFib(N);
 
    return 0;
}