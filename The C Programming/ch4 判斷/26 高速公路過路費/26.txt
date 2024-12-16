#include <stdio.h>

int main(){
    
    int k;
    scanf("%d", &k);
    
    if (k <= 20) {
        printf("%d\n", k * 5);
    } else if (k <= 100) {
        printf("%d\n", 20 * 5 + (k - 20) * 8);
    } else {
        printf("%.0f\n", (20 * 5 + (k - 20) * 8) * 0.9);
    }
    
    return 0;
}