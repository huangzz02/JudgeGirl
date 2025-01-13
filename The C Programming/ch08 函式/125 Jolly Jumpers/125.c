#include <stdio.h>

//Jolly_Jumpers.h
void Jolly_Jumpers(int Array[], int size);

//Jolly_Jumpers.c
void Jolly_Jumpers(int Array[], int size) {
    int num[size];
    for (int i = 0; i < size; i++) {
        num[i] = 0;
    }

    int temp;
    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        temp = Array[i + 1] - Array[i];
        if (temp < 0) temp = -temp;
        
        int currunt = count;
        while (currunt > 0 && num[currunt - 1] > temp) {
            num[currunt] = num[currunt - 1];
            currunt--;
        }
        num[currunt] = temp;
        count++;
    }

    for (int i = 0; i < size - 1; i++) {
        if (num[i] != i + 1) {
            printf("Not jolly\n");
            return;
        }
    }
    printf("Jolly\n");
}

//main.c
int main() {
    int size;
    scanf("%d", &size);
 
    int Array[100], i;
    for (i = 0; i < size; i++) {
        scanf("%d", &Array[i]);
    }
 
    Jolly_Jumpers(Array, size);
    return 0;
}