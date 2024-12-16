#include <stdio.h>
#include <math.h>

int main() {
    int test_case;
    scanf("%d", &test_case);

    while (test_case--) {
        int n;
        scanf("%d", &n);

        int arr_a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr_a[i]);
        }

        int s = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr_a[j] <= arr_a[i]) {
                    s++;
                }
            }
        }

        printf("%d\n", s);
    }
    return 0;
}