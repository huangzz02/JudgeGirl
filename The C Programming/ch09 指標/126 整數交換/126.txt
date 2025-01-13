#include <stdio.h>

//swap.h
void swap(int *x, int *y);

//swap.c
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

//main.c
int main(){
 
    int a;
    int b;
 
    scanf("%d %d", &a, &b);    
    swap(&a, &b);
    printf("%d %d\n", a, b);
 
    return 0;
 
}