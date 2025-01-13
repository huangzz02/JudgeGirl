#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    
    if (a <= 1500) {
        printf("80\n");
    } else {
        a = a - 1500;
        if (a % 500 != 0) {
            printf("%d\n", 80 + (a / 500 + 1) * 5);
        } else {
            printf("%d\n", 80+ (a / 500) * 5);
        }
    }
    
    return 0;
}