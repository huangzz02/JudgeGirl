#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
void time_computation(int *ans, int* arr, int buff, int l, int r) {
    if (l == r) {  
        int power = 1;
        int time = 0;
        for (int i = 0; i <= r; i++) {
            time += (arr[i] + power - 1) / power; // ceiling division
            power += buff;
        }
        if (time < *ans) *ans = time;
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(&arr[l], &arr[i]);
        time_computation(ans, arr, buff, l + 1, r);
        swap(&arr[l], &arr[i]); 
    }
}
 
int main() {
    int N = 0, buff = 0;
    scanf("%d %d", &N, &buff);
    int *arr = malloc(N * sizeof(int));
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
 
    int ans = INT_MAX;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    time_computation(&ans, arr, buff, 1, N - 1);
 
    printf("%d\n", ans);
    free(arr);
}
/*
    Lines 41 ~ 47 are intended to prevent TLE (without this part you'll only get TLE85).
    (If you don't want to waste time performing bubble sort, 
     you can simply swap the smallest element with the first one.
     This is because the algorithm always starts from the smallest element in the array.)
*/