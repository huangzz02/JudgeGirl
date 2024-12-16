#include <stdio.h>

//mymul.h
int mymul(int *a, int size);

//mymul.c
int mymul(int *a, int size) {
    int s = 1;
    for (int i = 0; i < size; i++) {
        s *= a[i];
    }
    return s;
}

//main.c
int main(){
    int data[4] = {};
    for(int i=0; i<4; i++){
          scanf("%d", &data[i]);
      }
    int size = sizeof(data) / sizeof(data[0]);
    printf("%d\n", mymul(data, size));
    return 0;
}