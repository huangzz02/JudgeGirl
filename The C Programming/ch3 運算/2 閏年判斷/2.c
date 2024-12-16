#include <stdio.h>
#include <stdbool.h>

int main() {
    int a;
    scanf("%d", &a);
    a = a + 1911;

    bool k = ( a % 4 == 0 && a % 100 != 0 ) || a % 400 == 0;
    printf("%d\n", k);

    return 0;
}