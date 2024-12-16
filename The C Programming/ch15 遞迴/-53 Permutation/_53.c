#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void print(int *data, int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            if (i == 0)  printf("%d", data[i]);
            else printf(" %d", data[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&data[start], &data[i]);
        print(data, start + 1, end);

        qsort(&data[start + 1], end - start, sizeof(int), compare);
//   or qsort(data + start + 1, end - start, sizeof(int), compare);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int data[9];
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    qsort(data, n, sizeof(int), compare);

    print(data, 0, n - 1);
    return 0;
}