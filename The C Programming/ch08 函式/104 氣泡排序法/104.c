#include <stdio.h>

//bubble_sort.h
void bubble_sort(int data[]);

//bubble_sort.c
void bubble_sort(int data[]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        if (i == 0) printf("%d", data[i]);
        else printf(" %d", data[i]);
    }
    printf("\n");
}

//main.c
int main() {
    int data[5];
    for(int i=0; i<5; i++)
        scanf("%d", &data[i]);

    bubble_sort(data);
 
    return 0;
}