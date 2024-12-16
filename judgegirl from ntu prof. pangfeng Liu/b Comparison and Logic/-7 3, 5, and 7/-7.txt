#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);

    if (a % 15 == 0 && a % 7 != 0) {
        printf("0\n");
    } else {
        printf("1\n");
    }
    
    return 0;
}