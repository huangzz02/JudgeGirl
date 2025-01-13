#include <stdio.h>

int main() {
    int test_case;
    scanf("%d", &test_case);

    while (test_case--) {
        int arr[4];
        for (int i = 0; i < 4; i++) {
            scanf("%d", &arr[i]);
        }

        int temp;
        for (int i = 1; i < 4; i++) {
            temp = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
        // a < b < c < d

        int a = arr[0], b = arr[1], c = arr[2], d = arr[3];
        if (a == b && c == d) {
            if (a == c) printf("square\n");
            else  printf("rectangle\n");
        }
        else if (a + b + c > d) printf("quadrangle\n");
        else printf("banana\n");
    }
    return 0;
}