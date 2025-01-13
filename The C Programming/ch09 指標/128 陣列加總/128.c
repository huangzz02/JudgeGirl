#include <stdio.h>

//mysum.h
int mysum(int *a, int size);

//mysum.c
int mysum(int *a, int size) {
    int s = 0;
    for (int i = 0; i < size; i++) {
        s += a[i];
    }
    return s;
}

//main.c
int main(){
 
    int data[4] = {};
    for(int i = 0; i < 4; i++) {
          scanf("%d", &data[i]);
      }
    int size = sizeof(data) / sizeof(data[0]);
    printf("%d\n", mysum(data, size));
 
    return 0;
 
}