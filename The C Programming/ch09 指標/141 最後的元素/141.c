#include <stdio.h>
#include <stdlib.h>

// LastElement.h
int extractMax(int* stone, int stoneSize);
void insert(int* stone, int stoneSize, int value);
int lastStoneWeight(int* stones, int stonesSize);

// LastElement.c
int extractMax(int* stone, int stoneSize) {
    int maxIndex = 0;
    for (int i = 0; i < stoneSize; i++) {
        if (stone[i] > stone[maxIndex]) {
            maxIndex = i;
        }
    }

    int max = stone[maxIndex];

    for (int i = maxIndex; i < stoneSize - 1; i++) {
        stone[i] = stone[i + 1];
    }

    return max;
}
 
void insert(int* stone, int stoneSize, int value) {
    stone[stoneSize] = value;
}
 
int lastStoneWeight(int* stones, int stonesSize) {
    int x, y;
    while (stonesSize > 1) {
        y = extractMax(stones, stonesSize);
        stonesSize--;
        x = extractMax(stones, stonesSize);
        stonesSize--;

        if (x != y) {
            insert(stones, stonesSize, y - x);
            stonesSize++;
        }
    }

    return (stonesSize == 1) ? stones[0] : 0;
}

// main.c
int main() {
    int n = 0;
    int ans;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
 
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    ans = lastStoneWeight(a, n);
    printf("%d", ans);
    free(a);
    return 0;
}