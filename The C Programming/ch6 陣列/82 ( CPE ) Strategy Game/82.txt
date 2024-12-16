#include <stdio.h>

int main() {
    int j, r;

    while (scanf("%d %d", &j, &r) == 2) {
        if (j == 0 && r == 0) break;

        int arr[j];
        for (int i = 0; i < j; i++) {
            arr[i] = 0;
        }

        for (int i = 0; i < r; i++) {
            for (int k = 0; k < j; k++) {
                int temp;
                scanf("%d", &temp);
                arr[k] += temp;
            }
        }

        int max = -1;
        int max_num;
        for (int i = 0; i < j; i++) {
            if (arr[i] >= max) {
                max = arr[i];
                max_num = i + 1;
            }
        }

        printf("%d\n", max_num);
    }
    return 0;
}