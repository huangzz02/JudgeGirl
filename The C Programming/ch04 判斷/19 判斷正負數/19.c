#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);

    if (a > 0) {
        printf("%d是正數\n", a);
        if (a <= 10000) {
            printf("A\n");
        } else {
            printf("B\n");
        }
    } else if (a < 0) {
        printf("%d是負數\n", a);
        if (a <= -10000) {
            printf("C\n");
        } else {
            printf("D\n");
        }
    } else {
        printf("0不是正數也不是負數\n");
    }

    return 0;
}