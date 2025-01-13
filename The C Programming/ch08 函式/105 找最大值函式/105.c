#include <stdio.h>

//getMax.h
void getMax(int data[], int size);

//getMax.c
void getMax(int data[], int size) {
    int max = -1;
    for (int i = 0; i < size; i++) {
        if (data[i] > max) max = data[i];
    }
    printf("%d", max);
}

//main.c
int main() {
    int data[5];
    int size = sizeof(data)/sizeof(int);
 
    for(int i=0; i<5; i++)
        scanf("%d", &data[i]);
 
    getMax(data, size);
 
    return 0;
}