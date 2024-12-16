#include <stdio.h>

//array_add.h
void array_add(int *a, int *b, int size);

//array_add.c
void array_add(int *a, int *b, int size) {
    for (int i = 0; i < size; i++) {
        a[i] += b[i];
    }
}

//main.c
int main(){
 
    int data1[4] = {};
    int data2[4] = {};
    int size = sizeof(data1) / sizeof(data1[0]);
    for(int i = 0; i < 4; i++) {
          scanf("%d", &data1[i]);
    }
    for(int i = 0; i < 4; i++) {
          scanf("%d", &data2[i]);
    }
    array_add(data1, data2, size);
    for(int i = 0; i < size; i++) {
        printf("%d ", data1[i]);
    }
    printf("\n");
    return 0;
}