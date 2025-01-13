#include <stdio.h>

int main() {
    float a;
    scanf("%f", &a);

    printf("%d\n%d\n", (int)(a*2*3.14), (int)(a*a*3.14));

    return 0;
}