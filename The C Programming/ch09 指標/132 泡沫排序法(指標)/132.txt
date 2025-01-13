#include <stdio.h>

//bubble.h
void bubble(int *arr);

//bubble.c
void bubble(int *arr) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        if (i == 0) printf("%d", arr[i]);
        else printf(" %d", arr[i]);
    }
    printf("\n");
}

//main.c
int main()
{
    int arr[5];
    int i;
    for( i=0 ; i<5 ; i++)
    {
        scanf("%d",&arr[i]);
    }
    bubble(arr);
}