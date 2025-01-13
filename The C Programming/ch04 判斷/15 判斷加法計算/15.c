#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d\n%d\n%d", &a, &b, &c);
    if (a + b == c) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}