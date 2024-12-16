#include <stdio.h>

int main(){
    
    int n;
    scanf("%d", &n);
    
    if (n <= 10) {
        printf("%d\n", n * 6);
    } else if (n <= 20) {
        printf("%d\n", 10 * 6 + (n - 10) * 2);
    } else if (n <= 40) {
        printf("%d\n", 10 * 6 + 10 * 2 + (n - 20) * 1);
    } else {
        printf("100\n");
    }
    
    return 0;
}