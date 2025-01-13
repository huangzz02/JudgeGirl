#include <stdio.h>

int main() {
    int test_case;
    scanf("%d", &test_case);

    while (test_case--) {
        int n, m = 0;
        scanf("%d", &n);

        int temp_n = n;
        int digit = 0;
        while (temp_n > 0) {
            temp_n /= 10;
            digit++;
        }

        for (int i = n; i >= (n - digit*9); i--) {
            int temp_i = i;
            int temp = 0;
            while (temp_i > 0) {
                temp += temp_i % 10;
                temp_i /= 10;
            }

            if (i + temp == n) {
                m = i;
            }
        }

        printf("%d\n", m);
    }
    return 0;
}