#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d\n%d\n%d", &a, &b, &c);

    printf("%d\n%d\n", (a * b + a * c + b *c) * 2, a * b * c);
    return 0;
}