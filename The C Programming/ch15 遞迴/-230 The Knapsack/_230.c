#include <stdio.h>

typedef struct data {
    int w;
    int v;
} data;

int backpack(data *arr, int n, int w_remain) {
    if (n == 0 || w_remain == 0) {
        return 0;
    }

    if (arr[n - 1].w > w_remain) {
        return backpack(arr, n - 1, w_remain);
    }

    int include = arr[n - 1].v + backpack(arr, n - 1, w_remain - arr[n - 1].w);
    int exclude = backpack(arr, n - 1, w_remain);

    return include > exclude ? include : exclude;
}

int main() {
    int n, w;
    scanf("%d %d", &n, &w);

    data arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].w);
        scanf("%d", &arr[i].v);
    }

    printf("%d\n", backpack(arr, n, w));

    return 0;
}